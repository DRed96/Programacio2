#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Programacio2/NEWDList.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ListTest
{
	TEST_CLASS(ListTemplateTest)
	{
	public:
		TEST_METHOD(Count)
		{
			
		}
		TEST_METHOD(AddPosition)
		{

			node * a, *b, *c;
			List test(a);
			int value;

			a = new node;
			b = new node;
			c = new node;
			a->next = b;
			b->next = c;
			c->next = NULL;
			test.Add(5, 3);
			value = test.Count();
			Assert::AreEqual(value, 3);
		}
		
	};
	
}
