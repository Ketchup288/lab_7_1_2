#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_7_1_2/lab_7_1_2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test
{
	TEST_CLASS(Test)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			int rowCount = 7;
			int colCount = 5;


			int a[7][5] = { {14, 14, 8, 14, 31},		// 0 зростання
							{-3, -3, 9, -6, 10},		// 1 зростання
							{25, -16, -6, 8, 3},		// 2 спадання
							{21, -5, 24, 28, 6},		// 3
							{16, 8, 25, 15, 6},			// 4
							{12, 17, 19, 19, 30},		// 5
							{6, 21, 24, 20, 11} };		// 6

			int* pa[7] = { a[0], a[1], a[2], a[3], a[4], a[5], a[6] };


			int b[7][5] = { {8, 14, 14, 14, 31},	   // 0 зростання
							{9, -6, -3, -3, 10},	   // 1 зростання
							{-6, 8, 25, -16, 3},	   // 2 спадання
							{24, 28, 21, -5, 6},	   // 3
							{25, 15, 16, 8, 6},		   // 4
							{19, 19, 12, 17, 30},	   // 5
							{24, 20, 6, 21, 11} };	   // 6

			Sort(pa, rowCount, colCount);

			for (int i = 0; i < rowCount; i++) {
				for (int j = 0; j < colCount; j++) {
					Assert::AreEqual(a[i][j], b[i][j]);
				}
			}
		}
	};
}
