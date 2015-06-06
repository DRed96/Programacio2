#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Programacio2/Queue_List2.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(Queue_RIC)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			p2Qeue<int> fifo;


			fifo.Push(11);
			fifo.Push(22);
			fifo.Push(33);

			Assert::AreEqual((int)fifo.Count(), 3);
			Assert::AreEqual((int)*(fifo.Peek(1)), 22);


			int result;
			bool r = fifo.Pop(result);
			/*
			Assert::AreEqual((int)result, 33);
			Assert::AreEqual((int)fifo.Count(), 2);
			*/
		}

	};
}