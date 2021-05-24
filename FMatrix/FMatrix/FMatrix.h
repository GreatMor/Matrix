#pragma once
#include <iostream>

struct SMatrix
{
	//constructor
	SMatrix(int N, int M, bool test);
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

	int Cols, Rows;
	float* Matr;
protected:	
	
	float** Matrix;
	
private:
	void ClearMatrix();
};


void printM(const SMatrix& m)
{
	for (int i = 1; i < m.Cols * m.Rows + 1; i++)
	{

		std::cout << m.Matr[i - 1];
		if (i % (m.Cols) == 0)
			std::cout << std::endl;

	}

}

int main()
{
	SMatrix OneMat(2,3, true);
	SMatrix TwoMat(2, 3, true);
	
	printM(OneMat);
	std::cout<<std::endl;
	printM(TwoMat);

	int a = 0;
	return 0;
}
