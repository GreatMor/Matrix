#include "FMatrix.h"

SMatrix::SMatrix(int N, int M)
	:Cols(N)
	,Rows(M)
	,Mmatrix(new float* [Cols])
{
	CreateMatrix();

	for (int i = 0; i < Cols; ++i)
	{
		for (int j = 0; j < Rows; ++j)
		{
			Mmatrix[i][j] = 0;
		}
	}
}

SMatrix::SMatrix(float* arr, int N, int M)
	:Cols(N)
	, Rows(M)
	,Mmatrix(new float* [Cols])
{
	CreateMatrix();
	int count = 0;
	for (int i = 0; i < Cols; ++i)
	{	
		for (int j = 0; j < Rows; ++j)
		{
			Mmatrix[i][j] = arr[count];
			count++;
		}
	}
}

SMatrix::SMatrix(SMatrix const& arr)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			//Mmatrix[i][j] = arr.Mmatrix[i][j];
		}
	}
}

void SMatrix::Multiply(SMatrix * arr)
{
	if (Cols == arr->Rows)
	{
		for (int i = 0; i < Cols; i++)
		{
			for (int j = 0; j < arr->Rows; j++)
			{
				for (int k = 0; k < Rows; k++)
				{
					std::cout <<  Mmatrix[i][k] << "*" << arr->Mmatrix[k][j] << "\t" << std::endl;
				}
				
			}
		
		}
	}
	
}

void SMatrix::PrintMatrix(const SMatrix& A)
{
	for (int i = 0; i < A.Cols; ++i)
	{
		for (int j = 0; j < A.Rows; ++j)
		{
			std::cout << A.Mmatrix[i][j] << "  " << "\t";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
}

void SMatrix::CreateMatrix()
{
	for (int i = 0; i < Cols; i++)
	{
		Mmatrix[i] = new float[Rows];
	}
}

SMatrix* SMatrix::operator*(const SMatrix& mat)
{
	SMatrix* Mmatr();
	if (Cols == mat.Rows)
	{		
		for (int i = 0; i < Cols; i++)
		{
			for (int j = 0; j < mat.Rows; j++)
			{
				for (int k = 0; k < Rows; k++)
				{
					Mmatr.Mmatrix[i][k] += Mmatrix[i][k] * mat.Mmatrix[k][j];
					//std::cout << Mmatrix[i][k] << "*" << mat.Mmatrix[k][j] << "\t" << std::endl;
				}
			}
		}
	}
	return Mmatr;
}

//
//void SMatrix::PrintMatrix()
//{
//	for (int i = 0; i < 4; i++)
//	{
//		for (int j = 0; j < 4; ++j)
//		{
//			std::cout << Mmatrix[i][j] << "  " << "\t";
//		}
//		std::cout << std::endl;
//	}
//}

