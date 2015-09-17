#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Programacio2/List.h"
#include "../Programacio2/DynArray.h"
#include "../Programacio2/String.h"
#include "../Programacio2/Tree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(EXAMEN_FINAL)
	{
	public:
		
		TEST_METHOD(EXAM_ListInsert)
		{
			List<int> mylist;
			List<int> mylist2;

			mylist2.add(1);
			mylist2.add(2);
			mylist2.add(3);

			List<int> mylist3;

			mylist3.add(4);
			mylist3.add(5);
			mylist3.add(6);

			mylist.insertAfter(0, mylist2);

			Assert::AreEqual(mylist[0], 1);
			Assert::AreEqual(mylist[1], 2);
			Assert::AreEqual(mylist[2], 3);

			mylist.insertAfter(1, mylist3);
			Assert::AreEqual(mylist[0], 1);
			Assert::AreEqual(mylist[1], 2);
			Assert::AreEqual(mylist[2], 4);
			Assert::AreEqual(mylist[3], 5);
			Assert::AreEqual(mylist[4], 6);
			Assert::AreEqual(mylist[5], 3);

			mylist.insertAfter(0, mylist3);
			Assert::AreEqual(mylist[0], 1);
			Assert::AreEqual(mylist[1], 4);
			Assert::AreEqual(mylist[2], 5);
			Assert::AreEqual(mylist[3], 6);
			Assert::AreEqual(mylist[4], 2);
			Assert::AreEqual(mylist[5], 4);
			Assert::AreEqual(mylist[6], 5);
			Assert::AreEqual(mylist[7], 6);
			Assert::AreEqual(mylist[8], 3);
			Assert::IsTrue((node<int>*) &mylist[0] == mylist.start);
			Assert::IsTrue((node<int>*) &mylist[8] == mylist.end);
		}

		TEST_METHOD(EXAM_SString_cut)
		{
			String s1("Hola mundo");
			s1.Cut(2, 5);
			Assert::AreEqual((int)strcmp("Houndo", s1.getString()), 0);
			s1.Cut(3, 0);
			Assert::AreEqual((int)strcmp("Hou", s1.getString()), 0);
		}

		TEST_METHOD(EXAM_DynArray_Operator_concat)
		{
			DynArray<int> array(5);
			array.PushBack(1);
			array.PushBack(2);
			array.PushBack(4);
			array.PushBack(5);
			array.PushBack(8);
			DynArray<int> array2;
			array2.PushBack(991);
			array2.PushBack(992);
			array2.PushBack(993);
			array += array2;
			Assert::AreEqual((int)array.count(), 8);
			Assert::AreEqual((int)array[0], 1);
			Assert::AreEqual((int)array[1], 2);
			Assert::AreEqual((int)array[2], 4);
			Assert::AreEqual((int)array[3], 5);
			Assert::AreEqual((int)array[4], 8);
			Assert::AreEqual((int)array[5], 991);
			Assert::AreEqual((int)array[6], 992);
			Assert::AreEqual((int)array[7], 993);
		}

		TEST_METHOD(EXAM_TreeCalcaddition)
		{
			
			Tree<int> tree;
			//He vist que el meu add funciona amb un punter com a argument
			//En la meva classe, el node root no esta suposat que tingui cap valor
			tree_node<int> * iterative;
			tree_node<int> * s1;
			tree_node<int> * s2;
			iterative = tree.add(1, NULL);
			
			
			s1 = tree.add(2, iterative);
			tree.add(3, iterative);
			s2 = tree.add(4, iterative);

			tree.add(5, s1);
			tree.add(6, s1);
			tree.add(7, s1);

			tree.add(8, s2);
iterative = tree.add(9, s2);

	   tree.add(10, iterative);

		//Assert::AreEqual((int)tree.CalcadditionRecursive(), 55);
			Assert::AreEqual((int)tree.CalcadditionIterative(), 55);
		}
	};
}