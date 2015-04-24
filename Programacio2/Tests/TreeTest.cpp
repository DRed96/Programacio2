#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Programacio2/Tree.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(TreeTest)
	{
	public:
		
		TEST_METHOD(TreeAdd)
		{
			Tree<int> test;
			
			Assert::AreEqual(0, 0);
		}

		
	};
}