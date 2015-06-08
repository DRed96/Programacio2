#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Programacio2/Queue_List.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(Queue_RIC)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Queue_List<int> fifo;

			
			fifo.PushBack(11);
			fifo.PushBack(22);
			fifo.PushBack(33);

			Assert::AreEqual((int)fifo.getSize(), 3);
			Assert::AreEqual((int)(fifo[1]), 22);


			int result;
			bool r = fifo.PopFirst(result);
			
			Assert::AreEqual(result, 33);
			Assert::AreEqual((int)fifo.getSize(), 2);
			
		}

	};
}