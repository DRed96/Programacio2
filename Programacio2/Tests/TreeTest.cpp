#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Programacio2/Tree.h"
#include "../Programacio2/List.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(TreeTest)
	{
	public:
		
		TEST_METHOD(Add)
		{
			Tree<int> test;
			//OPERATOR?
			tree_node<int> * s1;
			tree_node<int> * s2;
			tree_node<int> * it; //ITERATIVE NODE
			test.Add(9, NULL);
			
			s1 = test.Add(11,test.root);
			s2 = test.Add(5, test.root);

			test.Add(3, s1);
			test.Add(7, s1);

	   it = test.Add(2, s1->sons[0]);
			test.Add(4, s1->sons[0]);
			test.Add(1, it);

			test.Add(6, s1->sons[1]);
			test.Add(8, s1->sons[1]);

			test.Add(10, s2);
			test.Add(12, s2);


			Assert::AreEqual(9, test.root->data);
			Assert::AreEqual(test.root->sons[0]->data, 11);
			Assert::AreEqual(test.root->sons[1]->data, s2->data);

			Assert::AreEqual(s1->sons[0]->data, 3);
			Assert::AreEqual(s1->sons[1]->data, 7);

			Assert::AreEqual(s1->sons[0]->sons[0]->data, 2);
			Assert::AreEqual(s1->sons[0]->sons[1]->data, 4);
			Assert::AreEqual(s1->sons[0]->sons[0]->sons[0]->data, 1);
			
			Assert::AreEqual(s1->sons[1]->sons[0]->data, 6);
			Assert::AreEqual(s1->sons[1]->sons[1]->data, 8);


			Assert::AreEqual(s2->sons[0]->data, 10);
			Assert::AreEqual(s2->sons[1]->data, 12);
		}

		TEST_METHOD(Tree_PostOrderIT_2)
		{
			Tree<char> test;
			//OPERATOR?
			tree_node<char> * s1;
			tree_node<char> * s2;
		//	tree_node<char> * it; //ITERATIVE NODE
			
			test.Add('F', NULL);

			s1 = test.Add('B', test.root);
			s2 = test.Add('G', test.root);

			test.Add('A', s1);
			test.Add('C', s1);

			test.Add('D', s1->sons[1]);
			test.Add('E', s1->sons[1]);

			test.Add('H', s2);
			test.Add('I', s2->sons[0]);


			List<tree_node<char>*>* output;
			output = new List<tree_node<char>*>;

			//		test.PostorderIT(output);


	//		Assert::AreEqual(output->getStart()->data->data, 'F');
			/*Assert::AreEqual(output[1], 'F');
			Assert::AreEqual(output[2], 'F');
			Assert::AreEqual(output[3], 'F');
			Assert::AreEqual(output[4], 'F');
			Assert::AreEqual(output[5], 'F');
			Assert::AreEqual(output[6], 'F');
			Assert::AreEqual(output[7], 'F');
			Assert::AreEqual(output[8], 'F');
		
			Assert::AreEqual('F', test.root->data);
			Assert::AreEqual(test.root->sons[0]->data, s1->data);
			Assert::AreEqual(test.root->sons[1]->data, s2->data);

			Assert::AreEqual('B', s1->data);
			Assert::AreEqual('G', s2->data);

			Assert::AreEqual(s1->sons[0]->data, 'A');
			Assert::AreEqual(s1->sons[1]->data, 'C');

			Assert::AreEqual(s1->sons[0]->sons[0]->data, 2);
			Assert::AreEqual(s1->sons[0]->sons[1]->data, 4);
			Assert::AreEqual(s1->sons[0]->sons[0]->sons[0]->data, 1);

			Assert::AreEqual(s1->sons[1]->sons[0]->data, 6);
			Assert::AreEqual(s1->sons[1]->sons[1]->data, 8);


			Assert::AreEqual(s2->sons[0]->data, 10);
			Assert::AreEqual(s2->sons[1]->data, 12);*/
		}
	};
}