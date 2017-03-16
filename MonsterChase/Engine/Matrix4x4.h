#pragma once
#include "Vector4D.h"
class Matrix4x4
{
public:
	Matrix4x4();
	~Matrix4x4();

private:
	float m_11, m_12, m_13, m_14,
		m_21, m_22, m_23, m_24,
		m_31, m_32, m_33, m_34,
		m_41, m_42, m_43, m_44;
};


