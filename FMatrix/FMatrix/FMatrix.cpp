#include "FMatrix.h"

SMatrix::SMatrix(std::vector<std::vector<float>>& matrix/*, int n_size, int m_size*/)
{

	matrix = { {0,0,0},{0,0,0},{0,0,0} };
}

SMatrix::SMatrix(std::vector<std::vector<float>>& matrix, float x1[4], float x2[4], float x3[4], float x4[4])
{
	matrix = {	{x1[0],x1[1],x1[2],x1[3]},
				{x2[0],x2[1],x2[2],x2[3]},
				{x3[0],x3[1],x3[2],x3[3]},
				{x4[0],x4[1],x4[2],x4[3]}
			};
}

SMatrix::SMatrix(std::vector<std::vector<float>>& matrix, const float x1[4], const float x2[4], const float x3[4])
{
	matrix = { {x1[0],x1[1],x1[2]},
			   {x2[0],x2[1],x2[2]},
			   {x3[0],x3[1],x3[2]}
		     };
}

std::vector<std::vector<float>> SMatrix::GetIentityMatrix()
{
	std::vector<std::vector<float>> matrix = { {0,0,0,0}, {0,0,0,0}, {0,0,0,0}, { 0,0,0,0} };
	return matrix;
}

std::vector<std::vector<float>> SMatrix::CreatDiagonalMatrix(float x1, float x2, float x3, float x4)
{
	std::vector<std::vector<float>> matrix = { {x1,0,0,0},{0,x2,0,0},{0,0,x3,0}, { 0,0,0,x4} };	

	return matrix;
}

std::vector<std::vector<float>> SMatrix::CreateTriangularMatrix(float x1, float x2, float x3, float x4)
{
	std::vector<std::vector<float>> matrix = { {x1,x2,x3,x4},{0,x2,x3,x4},{0,0,x3,x4}, { 0,0,0,x4} };

	return matrix;
}
