#include "FMatrix.h"

SMatrix::SMatrix(int N, int M, bool test)
	: Cols(N)
	, Rows(M)
{
	int const Size = Cols * Rows;

	Matr = new float[Size];
		//CreateMatrix(Cols, Rows);

	for (int i = 0; i < Size; ++i)
	{
		Matr[i] = i;
	}
}
//SMatrix::SMatrix(int N, int M)
//	:Cols(N)
//	,Rows(M)
//	,Matrix(new float* [Cols])
//{
//	CreateMatrix(Cols, Rows);
//
//	for (int i = 0; i < Cols; ++i)
//	{
//		for (int j = 0; j < Rows; ++j)
//		{
//			Matrix[i][j] = 0;
//		}
//	}
//}
//
//SMatrix::SMatrix(float* arr, int N, int M)
//	:Cols(N)
//	,Rows(M)
//	,Matrix(new float* [Cols])
//{
//	CreateMatrix(Cols, Rows);
//	int count = 0;
//	for (int i = 0; i < Cols; ++i)
//	{	
//		for (int j = 0; j < Rows; ++j)
//		{
//			Matrix[i][j] = arr[count];
//			count++;
//		}
//	}
//}
//
//SMatrix::SMatrix(SMatrix const& arr)
//	:Cols(arr.Cols)
//	,Rows(arr.Rows)
//	,Matrix(new float* [Cols])
//{
//	CreateMatrix(arr.Cols, arr.Rows);
//	for (int i = 0; i < arr.Cols; i++)
//	{
//		for (int j = 0; j < arr.Rows; j++)
//		{
//			Matrix[i][j] = arr.Matrix[i][j];
//		}
//	}
//}


//SMatrix::~SMatrix()
//{
//	for (int i = 0; i < this->Rows; i++)
//	{
//		delete[] Matrix[i];
//	}
//
//	delete[] Matrix;	
//}

//void SMatrix::Multiply(SMatrix* InMat)
//{
//	SMatrix Mmatr(Cols, InMat->Rows);
//
//	if (Cols == InMat->Rows)
//	{
//		for (int i = 0; i < Cols; i++)
//		{
//			for (int j = 0; j < InMat->Rows; j++)
//			{
//				for (int k = 0; k < Rows; k++)
//				{
//					Mmatr.Matrix[i][j] += Matrix[i][k] * InMat->Matrix[k][j];
//				}
//			}
//		}
//		
//	}
//	Matrix = Mmatr.Matrix;
//
//}
//
//SMatrix SMatrix::Transpose()
//{
//	SMatrix TempMat(this->Rows, this->Cols);
//	for (int i = 0; i < this->Cols; i++)
//	{
//		for (int j = 0; j < this->Rows; j++)
//		{
//			TempMat.Matrix[j][i] = this->Matrix[i][j];
//			std::cout << "TempMat.Matrix[j][i] =" << TempMat.Matrix[j][i] << std::endl;
//		}
//	}
//	return TempMat;
//}
//
//void SMatrix::PrintMatrix(const SMatrix& A)
//{
//	for (int i = 0; i < A.Cols; ++i)
//	{
//		for (int j = 0; j < A.Rows; ++j)
//		{
//			std::cout << A.Matrix[i][j] << "  " << "\t";
//		}
//		std::cout << std::endl;
//	}
//
//	std::cout << std::endl;
//}
//
//void SMatrix::CreateMatrix(int Cols, int Rows)
//{
//	for (int i = 0; i < Cols; i++)
//	{
//		Matrix[i] = new float[Rows];
//	}
//}
//
//SMatrix SMatrix::operator*(const SMatrix& mat)
//{
//	SMatrix Mmatr(Cols, mat.Rows);
//	if (Cols == mat.Rows)
//	{		
//		for (int i = 0; i < Cols; i++)
//		{
//			for (int j = 0; j < mat.Rows; j++)
//			{
//				for (int k = 0; k < Rows; k++)
//				{
//					Mmatr.Matrix[i][j] += Matrix[i][k] * mat.Matrix[k][j];
//					std::cout << "Mmatr.Matrix["<< i << "][" << k <<"]"
//						<< "*" << "mat.Matrix["<< k <<"]"<< "[" << j <<"]" << "\t" << std::endl;
//				}
//			}
//		}
//	}
//	return Mmatr;
//}
//
//SMatrix SMatrix::operator*(const float value)
//{
//	SMatrix Mmatr(Cols, Rows);
//	
//	for (int i = 0; i < Cols; i++)
//	{
//		for (int j = 0; j < Rows; j++)
//		{
//			Mmatr.Matrix[i][j] = value* Matrix[i][j];
//		}
//	}
//	
//	return Mmatr;
//
//}
//
//SMatrix SMatrix::operator+(const SMatrix& InMat)
//{
//	SMatrix OutMmatr(InMat.Cols, InMat.Rows);
//	if (Cols == InMat.Cols && Rows == InMat.Rows)
//	{
//		
//		for (int i = 0; i < Cols; i++)
//		{
//			for (int j = 0; j < Rows; j++)
//			{
//				OutMmatr.Matrix[i][j] = Matrix[i][j] + InMat.Matrix[i][j];
//			}
//		}
//		return OutMmatr;
//	}
//	
//	return OutMmatr;
//	
//}
//
//SMatrix SMatrix::operator-(const SMatrix& InMat)
//{
//	SMatrix OutMmatr(InMat.Cols, InMat.Rows);
//	if (Cols == InMat.Cols && Rows == InMat.Rows)
//	{
//
//		for (int i = 0; i < Cols; i++)
//		{
//			for (int j = 0; j < Rows; j++)
//			{
//				OutMmatr.Matrix[i][j] = Matrix[i][j] - InMat.Matrix[i][j];
//				std::cout << "Matrix[" << i << "]["<< j<< "]" << Matrix[i][j]
//					<< "-" << "InMat.Matrix[" << i << "][" << j << "]" << InMat.Matrix[i][j] <<std::endl;
//			}
//		}
//		return OutMmatr;
//	}
//
//	return OutMmatr;
//
//}
//
//void SMatrix::ClearMatrix()
//{
//	
//		for (int j = 0; j < Rows-1; j++)
//			delete[] Matrix[j];
//	delete[] Matrix;
//}

//
//void SMatrix::PrintMatrix()
//{
//	for (int i = 0; i < 4; i++)
//	{
//		for (int j = 0; j < 4; ++j)
//		{
//			std::cout << Matrix[i][j] << "  " << "\t";
//		}
//		std::cout << std::endl;
//	}
//}

