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
			test.Pop();
			Assert::IsTrue(test.getElem() == 0);
			Assert::IsTrue(test.getMem() == 2);

		}

	};
}