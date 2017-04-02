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