#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Programacio2/List.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(dListTest)
	{
	public:
		
		TEST_METHOD(ListAdd)
		{
			List<int> mylist;
			Assert::AreEqual((int)mylist.Add(5), 1);
		}


		TEST_METHOD(ListBrackets)
		{
			List<int> mylist;
			mylist.Add(5);
			Assert::AreEqual(mylist[0], 5);
		}
	};
}