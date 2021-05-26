#include "Include/FMatrix.h"
#include <iomanip>


void printM(const SMatrix& m)
{
	//for (int i = 0; i < m.Cols * m.Rows; i++)
	//{

	//	std::cout << m.Matr[i ];
	//	if (i % (m.Cols) == 0)
	//		

	//}
	std::cout << std::endl;
	for (int j = 0; j < m.Rows; ++j) {
		for (int i = 0; i < m.Cols; ++i) {
			std::cout << std::setw(5) << m.Matr[j* m.Cols + i];
		}
		std::cout << std::endl;
	}

}

int main()
{
	SMatrix OneMat(12, 12, true);
	SMatrix TwoMat(10, 5, true);

	printM(OneMat);
	std::cout << std::endl;
	printM(TwoMat);

	int a = 0;
	return 0;
}
