#pragma once
#include <iostream>
#include <vector>

struct SMatrix
{	
	SMatrix(std::vector<std::vector<float>>& matrix/*, int n_size, int m_size*/);
	SMatrix(std::vector<std::vector<float>>& matrix, float x1[4], float x2[4], float x3[4], float x4[4]);
	SMatrix(std::vector<std::vector<float>>& matrix, const float x1[4], const float x2[4], const float x3[4]);

	//Static functions 
	static std::vector<std::vector<float>> GetIentityMatrix();
	
	//functions 
	std::vector<std::vector<float>> CreatDiagonalMatrix(float x1, float x2, float x3, float x4);
	std::vector<std::vector<float>> CreateTriangularMatrix(float x1, float x2, float x3, float x4);

private:

	float matrix[4][4];		
};

int main()
{
	float arr1[4]{ 1,2,3,2 };
	float arr2[4]{ 0,0,0,3 };
	float arr3[4]{ 41,42,43,4 };
	float arr4[4]{ 41,42,43,5 };

	std::vector<std::vector<float>> A = { {2,2}, {2,2} };
	SMatrix matrix(A, 2,2);
	
	std::vector<std::vector<float>> B;
	SMatrix matrix2(B, arr1, arr2, arr3, arr4);
	int a = 0;
	return 0;
}

