#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Programacio2/Stack.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(Stack_Test)
	{
	public:
		
		TEST_METHOD(StackFullTest)
		{
			Stack<int> test;
			int value = test.getElem();
			Assert::AreEqual(value , 0);
			test.PushBack(2);
			Assert::AreEqual(test.getElem(),test.getMem());
			Assert::IsTrue(test.getElem() ==1);
			test.PushBack(-5);
			Assert::AreEqual(test.getElem(), test.getMem());
			Assert::IsTrue(test.getElem() == 2);
			test.Pop();
			Assert::IsTrue(test.getElem() == 1);
			Assert::IsTrue(test.getMem() == 2);

		}

		TEST_METHOD(StackPop_Top)
		{
			Stack<int> test;
			
			test.PushBack(5);
			test.PushBack(4);
			test.PushBack(3);
			test.PushBack(2);
			test.PushBack(1);
			test.PushBack(0);

			Assert::IsTrue(test.Pop() == 0);
			Assert::IsTrue(test.Pop() == 1);
			Assert::IsTrue(test.Pop() == 2);
			Assert::IsTrue(test.Top() == 2);
			Assert::IsTrue(test.Pop() == 3);
			Assert::IsTrue(test.Pop() == 4);
			Assert::IsTrue(test.Pop() == 5);
			//All memory Poped
			Assert::IsTrue(test.Pop() == 0);
		}
	};
}