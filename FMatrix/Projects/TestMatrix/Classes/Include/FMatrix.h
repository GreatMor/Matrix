#pragma once
#include <iostream>

struct SMatrix
{
	//constructor New
	SMatrix(int N, int M, bool test);

	//constructor  Old
//	SMatrix(int N, int M);
//	SMatrix(float* arr, int N, int M);
//	SMatrix(SMatrix const& arr);

	//~SMatrix();

	//function 
	SMatrix Transpose();
//	void Multiply(SMatrix* InMat);
	
//	static void PrintMatrix(const SMatrix& A);
//	void CreateMatrix(int Cols, int Rows);
	

	//Operators 
//	SMatrix operator* (const float value);
//	SMatrix operator* (const SMatrix& InMat);
//	SMatrix operator+ (const SMatrix& InMat);
//	SMatrix operator- (const SMatrix& InMat);

	int Cols, Rows;
	float* Matr;
protected:	
	
//	float** Matrix;
	
private:
	void ClearMatrix();
};
