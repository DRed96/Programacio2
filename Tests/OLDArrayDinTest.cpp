#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Programacio2/OLDArrayD.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(ArrayDinTest)
	{
	public:
		
		TEST_METHOD(OAD_Reallocate)
		{
			ArrayD<int> test(5); 
			Assert::IsTrue(test.getMem() == 5);
			test.Reallocate(30);
			Assert::IsTrue(test.getMem() == 30);
			test.Reallocate(0);
			Assert::IsTrue(test.Reallocate(0) == false);

		}

		TEST_METHOD(OAD_PushBack)
		{
			ArrayD<int> test;
			test.PushBack(6);
			Assert::AreEqual(test[0], 6);
			test.PushBack(65);
			Assert::IsTrue(test.getMem() == 2);
			Assert::AreEqual(test[1], 65 );
			test.PushBack(0);
			test.PushBack(-0);




//			Assert::AreEqual(test[0], 6);
		//	Assert::AreEqual(test[1], 65);
			Assert::AreEqual(test[2], 0);
			Assert::AreEqual(test[3], 0 );


			Assert::IsTrue(test.getElem() == 4);
			Assert::IsTrue(test.getMem() == 4);
			test.Reallocate(30);
			test.PushBack(-150);
			Assert::IsTrue(test.getMem() == 30);
			Assert::IsTrue(test.getElem() == 5);
			ArrayD<int> test2(6);
			test2.PushBack(2);
			Assert::IsTrue(test2.getMem() == 6);
			Assert::IsTrue(test2.getElem() == 1);


		}
		
	};

}