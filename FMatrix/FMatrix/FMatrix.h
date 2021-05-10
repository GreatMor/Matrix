#pragma once
#include <iostream>
#include <vector>

struct SMatrix
{
	//constructor
	SMatrix(int Rows, int Cols);
	SMatrix(float* arr[], int N, int M);

	//destructor
	~SMatrix();

	//functions 
	void PrintMatrix();
	void CreateDiagonalMatrix();
	void CreateTriangularMatrix();

	bool IsUpperTriangularMatrix();
	//Getters
	float GetDet();

private:
	int n = 4;
	int m = 4;
	// array pointers
	float** Mmatrix = new float* [n];	
};

int main()
{
	int count = 1;
	float** arr = new float* [3];
	for (int i = 0; i < 3; i++)
	{
		arr[i] = new float[3];
	}

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			arr[i][j] = count++;
		}
	}

	SMatrix A(arr,3,3);
	A.PrintMatrix();
	std::cout << std::endl;

	A.CreateTriangularMatrix();
	A.PrintMatrix();
	std::cout << std::endl;

	//A.CreateDiagonalMatrix();	
	//A.PrintMatrix();
	//std::cout << std::endl;

	float det = A.GetDet();
	std::cout << det;
	int a = 0;
	std::cin >> a;
	return 0;
}

