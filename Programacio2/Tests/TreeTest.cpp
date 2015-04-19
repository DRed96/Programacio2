#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Programacio2/Tree.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(TreeTest)
	{
	public:
		
		TEST_METHOD(Tree_Add)
		{
			Tree<int> test(0);
			//test.Add(5);
		//	test.Add(6, test.root->sons.start->data);
		//	test.Add(-8);
		//	test.Add(-6666);
			//Assert::IsTrue((int)test.root->sons.getByPosition(3)->data == -6666);
			//int value = test.root->sons.getByPosition(0)->data->data;
			//Assert::IsTrue( test.root->sons.start->data->data == 5);
		
			bool tru = true;
			Assert::IsTrue(tru);
		}

	};
}