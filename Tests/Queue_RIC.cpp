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
			p2Qeue <int> fifo;S

			
			fifo.Push(11);
			fifo.Push(22);
			fifo.Push(33);

			Assert::AreEqual((int)fifo[1], 22);


			int result;
	
			fifo.Pop(result);
			
			Assert::AreEqual(result, 33);
		//	Assert::AreEqual((int)fifo.getSize(), 2);
			
		}

	};
}