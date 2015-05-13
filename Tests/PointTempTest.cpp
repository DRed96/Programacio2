#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Programacio2/PointTemp.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PointTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(P_IsZero)
		{
			Point<int> p1;
			bool check;
			p1.x = 20;
			p1.y = 15;

			p1.SetZero();
			check = p1.IsZero();
			Assert::IsTrue(check);
		}
		TEST_METHOD(P_OpMinus)
		{
			Point<int> p1, p2, p3;
			p1.x = 5;
			p1.y = 3;

			p2.x = 3;
			p2.y = 3;

			p3 = p1 - p2;
			Assert::AreEqual(p3.x, 2);
			Assert::AreEqual(p3.y, 0);

		}

		TEST_METHOD(P_OpPlusEqual)
		{
			Point<int> p1, p2;

			p1.x = 5;
			p1.y = 10;

			p2.x = 3;
			p2.y = 3;

			p1 += p2;
			Assert::AreEqual(p1.x, 8);
			Assert::AreEqual(p1.y, 13);

		}

		
		TEST_METHOD(P_Distance)
		{
			Point<int> p1, p2;
			
			int distance;
			p1.x = 4;
			p1.y = 3;

			p2.x = 5;
			p2.y = 3;
			distance = p1.DistanceTo(p2);

			Assert::AreEqual(distance, 1);
		}

		TEST_METHOD(P_OpNotEqual)
		{
			Point <int> p1, p2;
			bool check;

			p1.x = 5;
			p1.y = 10;

			p2.x = 20;
			p2.y = 10;

			check = p1.x != p2.x;
			Assert::IsTrue(check);
		}
		TEST_METHOD(P_OpPlus)
		{
			Point<int> p1, p2, p3;
			p1.x = 5;
			p1.y = 3;

			p2.x = 3;
			p2.y = 3;

			p3 = p1 + p2;
			Assert::AreEqual(p3.x, 8);
			Assert::AreEqual(p3.y, 6);
		}
		TEST_METHOD(P_SetZero)
		{
			Point<int> p1;
			p1.x = 20;
			p1.y = 15;
			p1.SetZero();
			Assert::AreEqual(p1.x, 0);
			Assert::AreEqual(p1.y, 0);

		}
		TEST_METHOD(P_OpEqualEqual)
		{
			Point<float> p1, p2;
			bool check;

			p1.x = 5.0f;
			p1.y = 10.0f;

			p2.x = 3.0f;
			p2.y = 3.0f;

			check = p1.x == p2.x;
			Assert::IsFalse(check);
		}

	};
}