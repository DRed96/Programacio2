#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Programacio2/Queue.h"
#include "../Programacio2/Queue_List.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(Queue_PushBack)
		{
			Queue<int> test;
			test.PushBack(2);
			Assert::AreEqual(test.getTop(), test.getStart());
			Assert::AreEqual(test.getTop(), 2);
			Assert::IsTrue(test.getMem() == 16);
			Assert::IsTrue(test.getElem() == 1);
			test.PushBack(3);
			test.PushBack(-50);

			int value2 = test[1];

			Assert::AreNotEqual(test.getTop(), test.getStart());
			Assert::AreEqual(test.getTop(), -50);
			Assert::AreEqual(test.getStart(), 2);
			Assert::AreEqual(value2, 3);

			Assert::IsTrue(test.getMem() == 16);
			Assert::IsTrue(test.getElem() == 3);

			for (int i = 0; i <= 999; i++){
				test.PushBack(i);
			}

			value2 = test[555];
			Assert::AreEqual(test.getTop(), 999);
			Assert::AreEqual(test.getStart(), 2);
			Assert::AreEqual(value2, 552);
			int mem = test.getMem();
			Assert::AreEqual(mem, 1008);
			Assert::IsTrue(test.getElem() == 1003);
		}

		TEST_METHOD(Queue_List_PushBack)
		{
			Queue_list <int >test;
			for (int i = 0; i < 1000; i++)
				test.PushBack(rand() % 1000);

			Assert::AreEqual((int)test.Count(), 1000);
			//Assert::IsTrue((int)test[200] != NULL);
		}

	};
}