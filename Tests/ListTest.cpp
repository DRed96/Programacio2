#include "stdafx.h"
#include <stdlib.h> 
#include "CppUnitTest.h"
#include "../Programacio2/DynArray.h"
#include "../Programacio2/List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(ListTest)
	{
	public:
		
		TEST_METHOD(List_add)
		{
			List<int> mylist;
			Assert::AreEqual((int)mylist.add(5), 1);
		}

		TEST_METHOD(List_add_Args)
		{
			List<int> t1;
			for (int i = 0; i <= 10; i++)
				t1.add(i);
			t1.add(-1, 5);
			for (int i = 0; i < 6; i++)
				Assert::AreEqual(t1[i], i);
			Assert::AreEqual(t1[6], -1);
		
				Assert::AreEqual(t1[7], 6);
				Assert::AreEqual(t1[8], 7);
				Assert::AreEqual(t1[9], 8);
				Assert::AreEqual(t1[10], 9);
		}
		TEST_METHOD(List_Corchetes)
		{
			List<int> test;
			test.add(0);
			test.add(1);
			test.add(4);
			test.add(11);
			test.add(-29);
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
			test.add(25);
			test.add(9);
			test.add(42);
			test.add(1);
			test.add(3);

			test.bubbleSort();

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
			test.add(25);
			test.add(9);
			test.add(42);
		
			
			test.swapNodes(test.start, test.start->next);

		//	Assert::IsTrue(1 == 2);
			Assert::AreEqual(test[0], 9);
			Assert::AreEqual(test[1], 25);
			Assert::AreEqual(test[2], 42);
			
		}

		TEST_METHOD(List_Insert)
		{
			List<int> t1;
			List<int> t2;
			for (int i = 0; i < 10; i++)
			{
				t1.add(i);

			}

			t2.add(-1);
			t2.add(-2);
			t2.add(-3);

			t1.Insert_List(2, t2);

			for (int i = 0; i < 2; i++)
			{
				Assert::AreEqual(t1[i], i);
			}

			Assert::AreEqual(t1[2], -1);
			Assert::AreEqual(t1[3], -2);
			Assert::AreEqual(t1[4], -3);

			Assert::AreEqual(t2[0], -1);
			Assert::AreEqual(t2[1], -2);
			Assert::AreEqual(t2[2], -3);
			
		}

		TEST_METHOD(List_Operator_PlusEqual)
		{
			List <int> t1;
			List <int> t2;

			for (int i = 0; i <= 100; i++)
				t1.add(i);

			t2.add(-1);
			t2.add(-2);
			t2.add(-3);
			t1 += t2;
//			Assert::AreEqual(1, 2);
			
			for (int i = 0; i <= 100; i++)
				Assert::AreEqual(t1[i], i);
			Assert::AreEqual(t1[101], -1);
			Assert::AreEqual(t1[102], -2);
			Assert::AreEqual(t1[103], -3);
		}

		TEST_METHOD(List_Delete)
		{
			List <int> t1;
		

			for (int i = 0; i <= 6; i++)
				t1.add(i);

			t1.del(t1.start->next->next);//2
			//::AreEqual(1, 2);

		
			Assert::AreEqual(t1[0], 0);
			Assert::AreEqual(t1[1], 1);
			Assert::AreEqual(t1[2], 3);
			Assert::AreEqual(t1[3], 4);
			Assert::AreEqual(t1[4], 5);
		
		}
		TEST_METHOD(List_copy_to_Array)
		{
			List <int> l1;
			DynArray <int> *ptr = NULL;

			for (int i = 0; i <= 15; i++)
				l1.add(i);

			Assert::IsFalse(l1.copyToArray(ptr));

			ptr = new DynArray<int>;
			l1.copyToArray(ptr);

			for (int j = 0; j < 15; j++)
			{
				Assert::AreEqual(ptr->operator[](j), l1[j]);
				Assert::AreEqual(ptr->operator[](j), j);
			}

			ptr->~DynArray();
			l1.copyToArray(ptr);

			for (int j = 0; j < 15; j++)
			{
				Assert::AreEqual(ptr->operator[](j), l1[j]);
				Assert::AreEqual(ptr->operator[](j), j);
			}
		}
	};
}