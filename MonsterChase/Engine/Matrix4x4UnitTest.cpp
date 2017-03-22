#include "Matrix4x4UnitTest.h"
#include "Matrix4x4.h"

#include <assert.h>
#include <algorithm>
#include <vector>
#include "time.h"
bool Matrix4x4_UnitTest() {
	Matrix4x4 test_matrix(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f, 16.0f);
	
	// test constructor and [][] operator
	assert(test_matrix[1][1] == 1.0f);
	assert(test_matrix[2][3] == 7.0f);
	assert(test_matrix[3][2] == 10.0f);
	assert(test_matrix[4][4] == 16.0f);

	// test set row
	// set the first row to all 0.0
	test_matrix.set_row(1, 0.0f, 0.0f, 0.0f, 0.0f);
	assert(test_matrix[1][1] == 0.0f);
	assert(test_matrix[1][2] == 0.0f);
	assert(test_matrix[1][3] == 0.0f);
	assert(test_matrix[1][4] == 0.0f);
	return true;
}