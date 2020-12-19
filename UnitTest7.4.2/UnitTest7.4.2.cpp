#include "pch.h"
#include "CppUnitTest.h"
#include "../laba7.4.2/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest742
{
	TEST_CLASS(UnitTest742)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int rowCount = 2, colCount = 2;
			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				a[i] = new int[colCount];
			int* masuv_min = new int[rowCount];
			int* masuv_max = new int[colCount];
			a[0][0] = 1, a[0][1] = -2, a[1][0] = 13, a[1][1] = -4;
			Sidlova(a, rowCount, colCount, 0, 1, masuv_min, a[0][0]);
			Sidlova1(a, rowCount, colCount, 1, 0, masuv_max, a[0][0]);
			Sidlova2(a, rowCount, colCount, 0, 0, masuv_min, masuv_max);
			Assert::AreEqual(a[1][0], 13);
			delete[]a;
			delete[] masuv_min;
			delete[] masuv_max;
		}
	};
}
