#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Programacio2/Bubble.h"
#include <stdlib.h>
#include "../Programacio2/log.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(BubbleTest)
	{
	public:
		
		TEST_METHOD(BubbleTEST)
		{
			p2DynArray<int>* test;
			test = new p2DynArray<int>;
			test->PushBack(2);
			test->PushBack(3);
			test->PushBack(6);
			test->PushBack(1);
			test->PushBack(8);
			
			for (int i = 0; i < 10000; i++)
			{
				
				test->PushBack(rand() % 10000);
			}

			int iterations = Bubble(test);
			//LOG ("%d", iterations);
			Assert::AreEqual(iterations, 0); //99359728
			
		}

	};
}