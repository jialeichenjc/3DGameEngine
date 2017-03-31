#include "Matrix4x4.h"

void Matrix4x4::scale(Vector4D & i_target_vec, Vector4D & i_scale_vec) {
	this->set_each_elem(i_scale_vec.x(), 0.0f, 0.0f, 0.0f,
		0.0f, i_scale_vec.y(), 0.0f, 0.0f,
		0.0f, 0.0f, i_scale_vec.u(), 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f);
	i_target_vec = (*this) * i_target_vec;
}

void Matrix4x4::rotate(Vector4D & i_target_vec, Vector4D & i_rot_vec) {

}

void Matrix4x4::translate(Vector4D & i_target_vec, Vector4D & i_trans_vec) {

}