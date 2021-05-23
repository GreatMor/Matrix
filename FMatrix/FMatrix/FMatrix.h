#pragma once
#include <iostream>

struct SMatrix
{
	//constructor
	SMatrix();
	SMatrix(int N, int M);
	SMatrix(float* arr, int N, int M);
	SMatrix(SMatrix const& arr);

	//~SMatrix();

	//function 
	SMatrix Transpose();
	void Multiply(SMatrix* InMat);
	
	static void PrintMatrix(const SMatrix& A);
	void CreateMatrix(int Cols, int Rows);
	

	//Operators 
	SMatrix operator* (const float value);
	SMatrix operator* (const SMatrix& InMat);
	SMatrix operator+ (const SMatrix& InMat);
	SMatrix operator- (const SMatrix& InMat);

protected:	
	int Cols, Rows;
	float** Mmatrix;	
private:
	void ClearMatrix();
};

int main()
{
	return 0;
}



