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
			//Abreviaton for iterative
			tree_node <int>* it;
			//Each pointer points to a son
			tree_node <int>* s1;
			tree_node <int>* s2;
			tree_node <int>* s3;
			tree_node <int>* testroot;

			testroot = test.Add(0, NULL);
			s1 = test.Add(100, testroot);
			
			test.Add(101, s1);
			test.Add(102, s1);
			test.Add(103, s1);


			s2 = test.Add(200, testroot);
			it = test.Add(201, s2);
			test.Add(211, it);

			s3 = test.Add(300, testroot);

			test.Add(221, NULL);
			Assert::AreEqual(testroot->sons[0]->data, 100);
			Assert::AreEqual(s1->sons[0]->data, 101);
			Assert::AreEqual(s1->sons[1]->data, 102);
			Assert::AreEqual(s1->sons[2]->data, 103);

			Assert::AreEqual(testroot->sons[1]->data, 200);
			Assert::AreEqual(s2->sons[0]->data, 201);
			Assert::AreEqual(s2->sons[0]->sons[0]->data, 211);
			Assert::IsTrue(s2->sons[0]->sons[0]->sons.getStart() == NULL);
			
			Assert::AreEqual(testroot->sons[2]->data, 300);		
		}

		/*TEST_METHOD(TreePreOrderIterative)
		{
			Tree<char> tree('F');

			tree.Add('B', 'F');
			tree.Add('G', 'F');
			tree.Add('A', 'B');
			tree.Add('D', 'B');
			tree.Add('X', 'B');
			tree.Add('C', 'D');
			tree.Add('E', 'D');
			tree.Add('I', 'G');
			tree.Add('H', 'I');

			List<p2TreeNode<char>*> list;
			tree.PreOrderIterative(&list);

			Assert::AreEqual((int)list.count(), 10);

			Assert::AreEqual((char)list[0]->data, 'F');
			Assert::AreEqual((char)list[1]->data, 'B');
			Assert::AreEqual((char)list[2]->data, 'A');
			Assert::AreEqual((char)list[3]->data, 'D');
			Assert::AreEqual((char)list[4]->data, 'C');
			Assert::AreEqual((char)list[5]->data, 'E');
			Assert::AreEqual((char)list[6]->data, 'X');
			Assert::AreEqual((char)list[7]->data, 'G');
			Assert::AreEqual((char)list[8]->data, 'I');
			Assert::AreEqual((char)list[9]->data, 'H');
		}
		*
		TEST_METHOD(TreePostOrderIterative)
		{
			Tree<char> tree;
			
			//Abreviaton for iterative
			//Each pointer points to a son
			tree_node <char>* s1;
			tree_node <char>* s2;
			tree_node <char>* testroot;

			testroot = tree.Add('F', NULL);
			s1 = tree.Add('B', testroot);
			s2 = tree.Add('G', testroot);
			tree.Add('A', s1);
			tree.Add('D', s1);
			tree.Add('C', s1->sons[1]);
			tree.Add('E', s1->sons[1]);
			tree.Add('I', s2);
			tree.Add('H', s2->sons[0]);

			List<tree_node<char>*> list;
			tree.PostorderIT(&list);

			Assert::AreEqual((int)list.count(), 9);

			Assert::AreEqual((char)list[0]->data, 'A');
			Assert::AreEqual((char)list[1]->data, 'C');
			Assert::AreEqual((char)list[2]->data, 'E');
			Assert::AreEqual((char)list[3]->data, 'D');
			Assert::AreEqual((char)list[4]->data, 'B');
			Assert::AreEqual((char)list[5]->data, 'H');
			Assert::AreEqual((char)list[6]->data, 'I');
			Assert::AreEqual((char)list[7]->data, 'G');
			Assert::AreEqual((char)list[8]->data, 'F');
		}
		/*
		TEST_METHOD(TreeInOrderIterative)
		{
			p2Tree<char> tree('F');

			tree.Add('B', 'F');
			tree.Add('G', 'F');
			tree.Add('A', 'B');
			tree.Add('D', 'B');
			tree.Add('C', 'D');
			tree.Add('E', 'D');
			tree.Add('I', 'G');
			tree.Add('H', 'I');

			p2List<p2TreeNode<char>*> list;
			tree.InOrderIterative(&list);

			Assert::AreEqual((int)list.count(), 9);

			Assert::AreEqual((char)list[0]->data, 'A');
			Assert::AreEqual((char)list[1]->data, 'B');
			Assert::AreEqual((char)list[2]->data, 'C');
			Assert::AreEqual((char)list[3]->data, 'D');
			Assert::AreEqual((char)list[4]->data, 'E');
			Assert::AreEqual((char)list[5]->data, 'F');
			Assert::AreEqual((char)list[6]->data, 'G');
			Assert::AreEqual((char)list[7]->data, 'I');
			Assert::AreEqual((char)list[8]->data, 'H');
		}
		*/

		
		TEST_METHOD(TreePreOrder)
		{
			Tree<char> tree;

			//Abreviaton for iterative
			tree_node <char>* it;
			//Each pointer points to a son
			tree_node <char>* s1;
			tree_node <char>* s2;
			tree_node <char>* testroot;

			testroot = tree.Add('F', NULL);

			s1 = tree.Add('B', testroot);
			s2 = tree.Add('G', testroot);
			tree.Add('A', s1);
			tree.Add('D', s1);
			tree.Add('X', s1);
			tree.Add('C', s1->sons[1]);
			tree.Add('E', s1->sons[1]);
			it = tree.Add('I', s2);
			tree.Add('H', it);

			List<tree_node<char>*> list;
			tree.PreorderREC(list);

			Assert::AreEqual((int)list.count(), 10);

			Assert::AreEqual((char)list[0]->data, 'F');
			Assert::AreEqual((char)list[1]->data, 'B');
			Assert::AreEqual((char)list[2]->data, 'A');
			Assert::AreEqual((char)list[3]->data, 'D');
			Assert::AreEqual((char)list[4]->data, 'C');
			Assert::AreEqual((char)list[5]->data, 'E');
			Assert::AreEqual((char)list[6]->data, 'X');
			Assert::AreEqual((char)list[7]->data, 'G');
			Assert::AreEqual((char)list[8]->data, 'I');
			Assert::AreEqual((char)list[9]->data, 'H');
		}
		/*
		TEST_METHOD(TreePostOrder)
		{
			p2Tree<char> tree('F');

			tree.Add('B', 'F');
			tree.Add('G', 'F');
			tree.Add('A', 'B');
			tree.Add('D', 'B');
			tree.Add('C', 'D');
			tree.Add('E', 'D');
			tree.Add('I', 'G');
			tree.Add('H', 'I');

			p2List<p2TreeNode<char>*> list;
			tree.PostOrderRecursive(&list);

			Assert::AreEqual((int)list.count(), 9);

			Assert::AreEqual((char)list[0]->data, 'A');
			Assert::AreEqual((char)list[1]->data, 'C');
			Assert::AreEqual((char)list[2]->data, 'E');
			Assert::AreEqual((char)list[3]->data, 'D');
			Assert::AreEqual((char)list[4]->data, 'B');
			Assert::AreEqual((char)list[5]->data, 'H');
			Assert::AreEqual((char)list[6]->data, 'I');
			Assert::AreEqual((char)list[7]->data, 'G');
			Assert::AreEqual((char)list[8]->data, 'F');
		}

		TEST_METHOD(TreeInOrder)
		{
			p2Tree<char> tree('F');

			tree.Add('B', 'F');
			tree.Add('G', 'F');
			tree.Add('A', 'B');
			tree.Add('D', 'B');
			tree.Add('C', 'D');
			tree.Add('E', 'D');
			tree.Add('I', 'G');
			tree.Add('H', 'I');

			p2List<p2TreeNode<char>*> list;
			tree.InOrderRecursive(&list);

			Assert::AreEqual((int)list.count(), 9);

			Assert::AreEqual((char)list[0]->data, 'A');
			Assert::AreEqual((char)list[1]->data, 'B');
			Assert::AreEqual((char)list[2]->data, 'C');
			Assert::AreEqual((char)list[3]->data, 'D');
			Assert::AreEqual((char)list[4]->data, 'E');
			Assert::AreEqual((char)list[5]->data, 'F');
			Assert::AreEqual((char)list[6]->data, 'G');
			Assert::AreEqual((char)list[7]->data, 'I');
			Assert::AreEqual((char)list[8]->data, 'H');
		}

	*/

	};
}