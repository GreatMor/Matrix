#include "FMatrix.h"

SMatrix::SMatrix()
	:Cols(4)
	,Rows(4)
	,Mmatrix(new float* [Cols])
{
	CreateMatrix(Cols, Rows);

	for (int i = 0; i < Cols; ++i)
	{
		for (int j = 0; j < Rows; ++j)
		{
			Mmatrix[i][j] = 0;
		}
	}
}
SMatrix::SMatrix(int N, int M)
	:Cols(N)
	,Rows(M)
	,Mmatrix(new float* [Cols])
{
	CreateMatrix(Cols, Rows);

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
	,Rows(M)
	,Mmatrix(new float* [Cols])
{
	CreateMatrix(Cols, Rows);
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
	:Cols(arr.Cols)
	,Rows(arr.Rows)
	,Mmatrix(new float* [Cols])
{
	CreateMatrix(arr.Cols, arr.Rows);
	for (int i = 0; i < arr.Cols; i++)
	{
		for (int j = 0; j < arr.Rows; j++)
		{
			Mmatrix[i][j] = arr.Mmatrix[i][j];
		}
	}
}


//SMatrix::~SMatrix()
//{
//	for (int i = 0; i < this->Rows; i++)
//	{
//		delete[] Mmatrix[i];
//	}
//
//	delete[] Mmatrix;	
//}

void SMatrix::Multiply(SMatrix* InMat)
{
	SMatrix Mmatr(Cols, InMat->Rows);

	if (Cols == InMat->Rows)
	{
		for (int i = 0; i < Cols; i++)
		{
			for (int j = 0; j < InMat->Rows; j++)
			{
				for (int k = 0; k < Rows; k++)
				{
					Mmatr.Mmatrix[i][j] += Mmatrix[i][k] * InMat->Mmatrix[k][j];
				}
			}
		}
		
	}
	Mmatrix = Mmatr.Mmatrix;

}

SMatrix SMatrix::Transpose()
{
	SMatrix TempMat(this->Rows, this->Cols);
	for (int i = 0; i < this->Cols; i++)
	{
		for (int j = 0; j < this->Rows; j++)
		{
			TempMat.Mmatrix[j][i] = this->Mmatrix[i][j];
			std::cout << "TempMat.Mmatrix[j][i] =" << TempMat.Mmatrix[j][i] << std::endl;
		}
	}
	return TempMat;
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

void SMatrix::CreateMatrix(int Cols, int Rows)
{
	for (int i = 0; i < Cols; i++)
	{
		Mmatrix[i] = new float[Rows];
	}
}

SMatrix SMatrix::operator*(const SMatrix& mat)
{
	SMatrix Mmatr(Cols, mat.Rows);
	if (Cols == mat.Rows)
	{		
		for (int i = 0; i < Cols; i++)
		{
			for (int j = 0; j < mat.Rows; j++)
			{
				for (int k = 0; k < Rows; k++)
				{
					Mmatr.Mmatrix[i][j] += Mmatrix[i][k] * mat.Mmatrix[k][j];
					std::cout << "Mmatr.Mmatrix["<< i << "][" << k <<"]"
						<< "*" << "mat.Mmatrix["<< k <<"]"<< "[" << j <<"]" << "\t" << std::endl;
				}
			}
		}
	}
	return Mmatr;
}

SMatrix SMatrix::operator*(const float value)
{
	SMatrix Mmatr(Cols, Rows);
	
	for (int i = 0; i < Cols; i++)
	{
		for (int j = 0; j < Rows; j++)
		{
			Mmatr.Mmatrix[i][j] = value* Mmatrix[i][j];
		}
	}
	
	return Mmatr;

}

SMatrix SMatrix::operator+(const SMatrix& InMat)
{
	SMatrix OutMmatr(InMat.Cols, InMat.Rows);
	if (Cols == InMat.Cols && Rows == InMat.Rows)
	{
		
		for (int i = 0; i < Cols; i++)
		{
			for (int j = 0; j < Rows; j++)
			{
				OutMmatr.Mmatrix[i][j] = Mmatrix[i][j] + InMat.Mmatrix[i][j];
			}
		}
		return OutMmatr;
	}
	
	return OutMmatr;
	
}

SMatrix SMatrix::operator-(const SMatrix& InMat)
{
	SMatrix OutMmatr(InMat.Cols, InMat.Rows);
	if (Cols == InMat.Cols && Rows == InMat.Rows)
	{

		for (int i = 0; i < Cols; i++)
		{
			for (int j = 0; j < Rows; j++)
			{
				OutMmatr.Mmatrix[i][j] = Mmatrix[i][j] - InMat.Mmatrix[i][j];
				std::cout << "Mmatrix[" << i << "]["<< j<< "]" << Mmatrix[i][j]
					<< "-" << "InMat.Mmatrix[" << i << "][" << j << "]" << InMat.Mmatrix[i][j] <<std::endl;
			}
		}
		return OutMmatr;
	}

	return OutMmatr;

}

void SMatrix::ClearMatrix()
{
	
		for (int j = 0; j < Rows-1; j++)
			delete[] Mmatrix[j];
	delete[] Mmatrix;
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

