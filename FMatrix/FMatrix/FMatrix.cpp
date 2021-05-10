#include "FMatrix.h"

SMatrix::SMatrix(int Rows, int Cols)
{	
	n = Rows;
	m = Cols;

	for (int i = 0; i < n; i++)
	{
		Mmatrix[i] = new float[m];
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			Mmatrix[i][j] = 0;
		}
	}
}

SMatrix::SMatrix(float* arr[], int Rows, int Cols)
{
	n = Rows;
	m = Cols;

	for (int i = 0; i < n; i++)
	{
		Mmatrix[i] = new float[m];
	}

	for (int i = 0; i < Rows; ++i)
	{
		for (int j = 0; j < Cols; ++j)
		{
			Mmatrix[i][j] = arr[i][j];
		}
	}
}

SMatrix::~SMatrix()
{
	for (int i = 0; i < m; ++i)
	{
		delete[] Mmatrix[i];
	}
	delete[] Mmatrix;
}

void SMatrix::PrintMatrix()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; ++j)
		{
			std::cout << Mmatrix[i][j] << "  " << "\t";
		}
		std::cout << std::endl;
	}
}


void SMatrix::CreateDiagonalMatrix()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i == j)
				Mmatrix[i][j] = Mmatrix[i][j];
			else
				Mmatrix[i][j] = 0;
		}
	}
}

void SMatrix::CreateTriangularMatrix()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i == j || i < j)
				Mmatrix[i][j] = Mmatrix[i][j];
			else
				Mmatrix[i][j] = 0;
		}
	}
}

bool SMatrix::IsUpperTriangularMatrix()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i > j)
			{
				if(Mmatrix[i][j] != 0)				
				return false;
			}
		}
	}
	return true;
}

float SMatrix::GetDet()
{
	float Det = 1;
	float CurrentValue = 1;
	if (IsUpperTriangularMatrix())
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (i == j)
				{
					Det *= Mmatrix[i][j];
				}
			}
		}
		return Det;
	}
	else
		return 0;
}
