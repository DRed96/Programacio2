#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Programacio2/DynArray.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(ArrayDTest)
	{
	public:
		
		TEST_METHOD(DynArray_ctor)
		{
			DynArray<int> array;
			Assert::AreEqual((int)array.GetCapacity(), MEM_CHUNK);
		}

		TEST_METHOD(DynArray_ctor_capacity)
		{
			DynArray<int> array(33);
			Assert::AreEqual((int)array.GetCapacity(), 33);
		}

		TEST_METHOD(DynArray_push_back)
		{
			DynArray<int> array;

			array.PushBack(1);
			array.PushBack(2);
			array.PushBack(3);
			Assert::AreEqual((int)array.GetCapacity(), MEM_CHUNK);
			Assert::AreEqual((int)array.Count(), 3);
		}

	

		TEST_METHOD(DynArray_clear)
		{
			DynArray<int> array;

			array.PushBack(1);
			array.PushBack(2);
			array.PushBack(3);
			array.Clear();

			Assert::AreEqual((int)array.GetCapacity(), MEM_CHUNK);
			Assert::AreEqual((int)array.Count(), 0);
		}


		TEST_METHOD(DynArray_op)
		{
			DynArray<int> array;

			array.PushBack(1);
			array.PushBack(2);
			array.PushBack(3);

			Assert::AreEqual(array[0], 1);
			Assert::AreEqual(array[1], 2);
			Assert::AreEqual(array[2], 3);
		}

		TEST_METHOD(DynArray_at)
		{
			DynArray<int> array;

			array.PushBack(1);
			array.PushBack(2);
			array.PushBack(3);

			Assert::AreEqual(*(array.At(0)), 1);
			Assert::AreEqual(*(array.At(1)), 2);
			Assert::AreEqual(*(array.At(2)), 3);
			Assert::IsNull(array.At(3));
		}

		TEST_METHOD(DynArray_resize)
		{
			DynArray<int> array;

			for (int i = 0; i < 999; ++i)
			{
				array.PushBack(i);
			}

			Assert::AreEqual(*(array.At(900)), 900);
			Assert::IsNull(array.At(1000));

			Assert::AreEqual((int)array.GetCapacity(), 1008);
			Assert::AreEqual((int)array.Count(), 999);
		}	

		TEST_METHOD(DynArray_Flip)
		{
			DynArray<int> test;
			for (int i = 0; i < 6; i++)
				test.PushBack(i);

			test.flip();

			Assert::AreEqual(test[0], 6);
			Assert::AreEqual(test[1], 5);
			Assert::AreEqual(test[2], 4);
			Assert::AreEqual(test[3], 3);
			Assert::AreEqual(test[4], 2);
			Assert::AreEqual(test[5], 1);
			Assert::AreEqual(test[6], 0);
			
		}

		TEST_METHOD(DynArray_Insert2)
		{
			DynArray<int> test;
			DynArray<int> test2;
			for (int i = 0; i < 6; i++)
			{
				test.PushBack(i);
				
			}

			test2.PushBack(-1);
			test2.PushBack(-2);
			test2.PushBack(-3);
			

			test.Insert(test2, 4);
			/*
			Assert::AreEqual(test[0], 0);
			Assert::AreEqual(test[1], 1);
			Assert::AreEqual(test[2], 2);
			Assert::AreEqual(test[3], 3);
//			Assert::AreEqual(test[4], -1);
			Assert::AreEqual(test[5], 5);
			Assert::AreEqual(test[6], 6);
			Assert::AreEqual(test[7], 4);
			Assert::AreEqual(test[8], 5);
			Assert::AreEqual(test[9], 6);*/


		}
	};
}