#pragma once
#include <iostream>
#include <vector>

struct SMatrix
{
	//constructor
	SMatrix(int N, int M);
	SMatrix(float* arr, int N, int M);
	SMatrix(SMatrix const& arr);

	//function 
	void Multiply(SMatrix * arr);
	static void PrintMatrix(const SMatrix& A);
	void CreateMatrix();

	//Operators 
	SMatrix operator* (const SMatrix& mat);
protected:
	int Cols, Rows;
	float** Mmatrix;	
};

int main()
{
	float arr[6]{ 1,2,4
				  ,2, 0,3};

	float arr1[6]{ 2, 5,
				   1, 3,
				   1, 1};

	SMatrix mat(arr, 2, 3);
	//mat.PrintMatrix();

	SMatrix mat2(arr1, 3, 2);
	//mat2.PrintMatrix();
	SMatrix* mat5();
	SMatrix mat3(arr, 2,3);
	mat5 = mat * mat2;
	SMatrix::PrintMatrix(mat3);
//mat.PrintMatrix();
	int as;
	std::cin >> as;
	return 0;
}

