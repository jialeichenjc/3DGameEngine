#include "Matrix4x4.h"
#define PI 3.14159265358979

void Matrix4x4::scale(Vector4D & i_target_vec, Vector4D & i_scale_vec) {
	this->set_each_elem(i_scale_vec.x(), 0.0f, 0.0f, 0.0f,
		0.0f, i_scale_vec.y(), 0.0f, 0.0f,
		0.0f, 0.0f, i_scale_vec.u(), 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f);
	i_target_vec = (*this) * i_target_vec;
}

void Matrix4x4::rotate(Vector4D & i_target_vec, Vector4D & i_rot_vec) {
	//this->set_each_elem()
}

void Matrix4x4::translate(Vector4D & i_target_vec, Vector4D & i_trans_vec) {
	this->set_each_elem(1.0f, 0.0f, 0.0f, i_trans_vec.x(),
		0.0f, 1.0f, 0.0f, i_trans_vec.y(),
		0.0f, 0.0f, 1.0f, i_trans_vec.u(),
		0.0f, 0.0f, 0.0f, 1.0f);
	i_target_vec = (*this) * i_target_vec;
}

void Matrix4x4::rotate_x(Vector4D & i_target_vec, float angle) {
	float r_angle = angle * PI / 180.0f;
	this->set_each_elem(1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, cos(r_angle), -sin(r_angle), 0.0f,
		0.0f, sin(r_angle), cos(r_angle), 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f);
	i_target_vec = (*this) * i_target_vec;
}

void Matrix4x4::rotate_y(Vector4D & i_target_vec, float angle) {
	float r_angle = angle * PI / 180.0f;
	this->set_each_elem(cos(r_angle), 0.0f, sin(r_angle), 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		-sin(r_angle), 0.0f, cos(r_angle), 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f);
	i_target_vec = (*this) * i_target_vec;
}

void Matrix4x4::rotate_z(Vector4D & i_target_vec, float angle) {
	float r_angle = angle * PI / 180.0f;
	this->set_each_elem(cos(r_angle), -sin(r_angle), 0.0f, 0.0f,
		sin(r_angle), cos(r_angle), 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f);
	i_target_vec = (*this) * i_target_vec;
}

Matrix4x4 & Matrix4x4::get_inversion() {
	Matrix4x4 result;
	float mat_det = this->get_det();
	if (mat_det != 0) {
		float r00 = (m_11*m_22*m_33 + m_21*m_32*m_13 + m_31*m_12*m_23 - m_31*m_22*m_13 - m_32*m_23*m_11 - m_33*m_21*m_12) / mat_det;
		float r01 = (m_31*m_22*m_03 + m_32*m_23*m_01 + m_33*m_21*m_02 - m_01*m_22*m_33 - m_21*m_32*m_03 - m_31*m_02*m_23) / mat_det;
		float r02 = (m_01*m_12*m_33 + m_11*m_32*m_03 + m_31*m_02*m_13 - m_31*m_12*m_03 - m_11*m_02*m_33 - m_01*m_32*m_13) / mat_det;
		float r03 = (m_21*m_12*m_03 + m_11*m_02*m_23 + m_01*m_22*m_13 - m_01*m_12*m_23 - m_11*m_22*m_03 - m_21*m_02*m_13) / mat_det;
		float r10 = (m_30*m_22*m_13 + m_20*m_12*m_33 + m_10*m_32*m_23 - m_10*m_22*m_33 - m_20*m_32*m_13 - m_30*m_12*m_23) / mat_det;
		float r20 = (m_10*m_21*m_33 + m_20*m_31*m_13 + m_30*m_11*m_23 - m_30*m_21*m_13 - m_20*m_11*m_33 - m_10*m_31*m_23) / mat_det;
		float r30 = (m_30*m_21*m_12 + m_20*m_11*m_32 + m_10*m_31*m_22 - m_10*m_21*m_32 - m_20*m_31*m_12 - m_30*m_11*m_22) / mat_det;
		float r11 = (m_00*m_22*m_33 + m_20*m_32*m_03 + m_30*m_02*m_23 - m_30*m_22*m_03 - m_20*m_02*m_33 - m_00*m_32*m_23) / mat_det;
		float r21 = (m_30*m_21*m_03 + m_20*m_01*m_33 + m_00*m_31*m_23 - m_00*m_21*m_33 - m_01*m_23*m_30 - m_03*m_20*m_31) / mat_det;
		float r31 = (m_00*m_21*m_32 + m_20*m_31*m_02 + m_30*m_01*m_22 - m_30*m_21*m_02 - m_20*m_01*m_32 - m_00*m_31*m_22) / mat_det;
		float r12 = (m_30*m_12*m_03 + m_10*m_02*m_33 + m_00*m_32*m_13 - m_00*m_12*m_33 - m_10*m_32*m_03 - m_30*m_02*m_13) / mat_det;
		float r32 = (m_30*m_11*m_02 + m_10*m_01*m_32 + m_00*m_31*m_12 - m_00*m_11*m_32 - m_10*m_31*m_02 - m_30*m_01*m_12) / mat_det;
		float r33 = (m_00*m_11*m_22 + m_01*m_12*m_20 + m_02*m_10*m_21 - m_20*m_11*m_02 - m_10*m_01*m_22 - m_00*m_21*m_12) / mat_det;
		float r13 = (m_00*m_12*m_23 + m_10*m_22*m_03 + m_20*m_02*m_13 - m_20*m_12*m_03 - m_10*m_02*m_23 - m_00*m_22*m_13) / mat_det;
		float r23 = (m_20*m_11*m_03 + m_10*m_01*m_23 + m_00*m_21*m_13 - m_00*m_11*m_23 - m_10*m_21*m_03 - m_20*m_01*m_13) / mat_det;
		float r22 = (m_00*m_11*m_33 + m_01*m_13*m_30 + m_03*m_10*m_31 - m_30*m_11*m_03 - m_10*m_01*m_33 - m_00*m_31*m_13) / mat_det;

		result.set_each_elem(r00, r01, r02, r03,
			r10, r11, r12, r13,
			r20, r21, r22, r23,
			r30, r31, r32, r33);
		return result;
	}
	
	else {
		return *this;
	}
}