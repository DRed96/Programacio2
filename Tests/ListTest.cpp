#include "stdafx.h"
#include <stdlib.h> 
#include "CppUnitTest.h"
#include "../Programacio2/List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(ListTest)
	{
	public:
		
		TEST_METHOD(List_Add)
		{
			List<int> mylist;
			Assert::AreEqual((int)mylist.Add(5), 1);
		}


		TEST_METHOD(List_Corchetes)
		{
			List<int> test;
			test.Add(0);
			test.Add(1);
			test.Add(4);
			test.Add(11);
			test.Add(-29);
			Assert::AreEqual((int)test[0], 0);
			Assert::AreEqual((int)test[1], 1);
			Assert::AreEqual((int)test[2], 4);
			Assert::AreEqual((int)test[3], 11);
			Assert::AreEqual((int)test[4], -29);
			//Assert::AreEqual((int)test[5], -29);
		}

		TEST_METHOD(List_Bubble)
		{
			List<int> test;
			test.Add(25);
			test.Add(9);
			test.Add(42);
			test.Add(1);
			test.Add(3);

			test.BubbleSort();

			Assert::AreEqual(test[0], 1);
			Assert::AreEqual(test[1], 3);
			Assert::AreEqual(test[2], 9);
			Assert::AreEqual(test[3], 25);
			Assert::AreEqual(test[4], 42);
			//Assert::AreEqual((int)test[5], -29);
		}
		
		TEST_METHOD(List_Swap)
		{
			List<int> test;
			test.Add(25);
			test.Add(9);
			test.Add(42);
			test.Add(1);
			test.Add(3);

		//	test.swapNodes();

			Assert::IsTrue(1 == 2);
			/*Assert::AreEqual(test[0], 1);
			Assert::AreEqual(test[1], 3);
			Assert::AreEqual(test[2], 9);
			Assert::AreEqual(test[3], 25);
			Assert::AreEqual(test[4], 42);
			*/
		}

		TEST_METHOD(List_Insert)
		{
			List<int> t1;
			List<int> t2;
			for (int i = 0; i < 10; i++)
			{
				t1.Add(i);

			}

			t2.Add(-1);
			t2.Add(-2);
			t2.Add(-3);

			t1.Insert(2, t2);

			for (int i = 0; i < 2; i++)
			{
				Assert::AreEqual(t1[i], i);
			}

			Assert::AreEqual(t1[2], -1);
			Assert::AreEqual(t1[3], -2);
			Assert::AreEqual(t1[4], -3);
			
		}
	};
}