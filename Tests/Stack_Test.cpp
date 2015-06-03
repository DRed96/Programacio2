#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Programacio2/Stack.h"
#include "../Programacio2/Stack_List.h"
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

			int checker = 0;
			test.Pop(checker);
			Assert::AreEqual(checker, 0);
			test.Pop(checker);
			Assert::AreEqual(checker, 1);
			test.Pop(checker);
			Assert::AreEqual(checker, 2);
			test.Pop(checker);
			Assert::AreEqual(checker, 3);
			test.Pop(checker);
			Assert::AreEqual(checker, 4);
			test.Pop(checker);
			Assert::AreEqual(checker, 5);	
			//All memory Poped
			test.Pop(checker);
			Assert::AreEqual(checker, 5);
		}

		TEST_METHOD(ListStack_FullTest)
		{
			/*Stack_List<int> test;
			int value = test.nElements;
			Assert::AreEqual(value, 0);
			test.PushBack(2);
			Assert::AreEqual(test.nElements, test.mem_alloc);
			Assert::IsTrue(test.nElements == 1);
			test.PushBack(-5);
			Assert::AreEqual(test.nElements, test.mem_alloc);
			Assert::IsTrue(test.nElements == 2);
			test.Pop();
			Assert::IsTrue(test.nElements == 1);
			Assert::IsTrue(test.mem_alloc == 2);*/
			//TODO

		}
	};
}