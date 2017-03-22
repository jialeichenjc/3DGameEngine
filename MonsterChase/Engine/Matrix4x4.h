#pragma once
#include "Vector4D.h"
class Matrix4x4
{
public:
	Matrix4x4() = default;
	Matrix4x4(float i_11, float i_12, float i_13, float i_14,
		float i_21, float i_22, float i_23, float i_24,
		float i_31, float i_32, float i_33, float i_34,
		float i_41, float i_42, float i_43, float i_44)
		: m_11(i_11), m_12(i_12), m_13(i_13), m_14(i_14),
		m_21(i_21), m_22(i_22), m_23(i_23), m_24(i_24),
		m_31(i_31), m_32(i_32), m_33(i_33), m_34(i_34),
		m_41(i_41), m_42(i_42), m_43(i_43), m_44(i_44) {
		
		row1 = new Vector4D(i_11, i_12, i_13, i_14);
		row2 = new Vector4D(i_21, i_22, i_23, i_24);
		row3 = new Vector4D(i_31, i_32, i_33, i_34);
		row4 = new Vector4D(i_41, i_42, i_43, i_44);

		matrix_vec[0] = row1;
		matrix_vec[1] = row2;
		matrix_vec[2] = row3;
		matrix_vec[3] = row4;
	}

	// proxy class to overload [][] operator
	class Proxy {
	public:
		Proxy(Vector4D i_vec) : vec4d(i_vec) {}

		float operator[](size_t i_index) {
			float result;
			switch (i_index) 
			{
			case 1:
				result = vec4d.x();
				break;
			case 2:
				result = vec4d.y();
				break;
			case 3:
				result = vec4d.u();
				break;
			case 4:
				result = vec4d.v();
				break;
			}
			return result;
		} // end of operator[]

	private:
		Vector4D vec4d;
	};

	// returns a new matrix whose rows are the columns of the original
	Matrix4x4 get_transpose(Matrix4x4 &i_matrix) {
		Matrix4x4 matrix;
		
		return matrix;
	}

	Proxy operator[] (size_t i_row) {
		Vector4D temp = *matrix_vec[i_row - 1];
		return Proxy(temp);
	}

	inline void set_row(int i_row, float i_1, float i_2, float i_3, float i_4) {
		//matrix_vec[i_row - 1] = Vector4D(i_1, i_2, i_3, i_4);
		switch (i_row)
		{
		case 1: 
			row1 = new Vector4D(i_1, i_2, i_3, i_4);
			m_11 = i_1;
			m_12 = i_2;
			m_13 = i_3;
			m_14 = i_4;
			break;
		case 2:
			row2 = new Vector4D(i_1, i_2, i_3, i_4);
			m_21 = i_1;
			m_22 = i_2;
			m_23 = i_3;
			m_24 = i_4;
			break;
		case 3:
			row3 = Vector4D(i_1, i_2, i_3, i_4);
			m_31 = i_1;
			m_32 = i_2;
			m_33 = i_3;
			m_34 = i_4;
			break;
		case 4:
			row4 = &Vector4D(i_1, i_2, i_3, i_4);
			m_41 = i_1;
			m_42 = i_2;
			m_43 = i_3;
			m_44 = i_4;
			break;
		default:
			break;
		}
	}


	// set values for each element in the matrix
	inline void set_each_elem(float i_11, float i_12, float i_13, float i_14,
		float i_21, float i_22, float i_23, float i_24,
		float i_31, float i_32, float i_33, float i_34,
		float i_41, float i_42, float i_43, float i_44) {
		m_11 = i_11;
		m_12 = i_12;
		m_13 = i_13;
		m_14 = i_14;
		m_21 = i_21;
		m_22 = i_22;
		m_23 = i_23;
		m_24 = i_24;
		m_31 = i_31;
		m_32 = i_32;
		m_33 = i_33;
		m_34 = i_34;
		m_41 = i_41;
		m_42 = i_42;
		m_43 = i_43;
		m_44 = i_44;
	}

	~Matrix4x4() {
		delete row1;
		delete row2;
		delete row3;
		delete row4;
	}

private:
	float m_11, m_12, m_13, m_14,
		m_21, m_22, m_23, m_24,
		m_31, m_32, m_33, m_34,
		m_41, m_42, m_43, m_44;

	Vector4D *row1;
	Vector4D *row2;
	Vector4D *row3;
	Vector4D *row4;

	// representation of this matrix as an array of Vector4D (for each row)
	Vector4D *matrix_vec[4];
};


