#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Programacio2/Tree.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(TreeTests)
	{
	public:

		TEST_METHOD(Tree_add)
		{
			Tree<int> test;
			//OPERATOR?
			tree_node<int> * s1;
			tree_node<int> * s2;
			tree_node<int> * it; //ITERATIVE NODE
			test.add(9, NULL);

			s1 = test.add(11, test.root);
			s2 = test.add(5, test.root);

			test.add(3, s1);
			test.add(7, s1);

			it = test.add(2, s1->sons[0]);
			test.add(4, s1->sons[0]);
			test.add(1, it);

			test.add(6, s1->sons[1]);
			test.add(8, s1->sons[1]);

			test.add(10, s2);
			test.add(12, s2);


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

		TEST_METHOD(Tree_Clear)
		{
			Tree<char> test;
			tree_node <char>* a;
			a = test.add('A');
			tree_node<char>* b;
			b = test.add('B', a);
			tree_node<char>* c;
			c = test.add('C', a);

			Assert::AreEqual(test.root->data, 'A');

			List <tree_node<int>*> output;
			test.clear();
			Assert::IsTrue(output.size == 0);

			Assert::AreEqual(test.root->sons.size, (unsigned int)0);
		}


		TEST_METHOD(Tree_Clear_2)
		{
			Tree<char> test;
			test.add('F', NULL);

			tree_node<char> * s1;
			tree_node<char> * s2;
			s1 = test.add('B', test.root);
			s2 = test.add('G', test.root);

			test.add('H', s2);
			test.add('I', s2->sons[0]);

			test.add('A', s1);
			test.add('D', s1);

			test.add('C', s1->sons[1]);
			test.add('E', s1->sons[1]);

			Assert::AreEqual(test.root->data, 'F');

			List <tree_node<int>*> output;
			test.clear(s1->sons[1]);

			Assert::AreEqual(test.root->data, 'F');
			Assert::IsTrue(output.size == 0);

			Assert::AreEqual(test.root->sons.size, (unsigned int)2);
			Assert::AreEqual(s1->sons.size, (unsigned int)1);
		}
		TEST_METHOD(Tree_PostOrderIT)
		{
			Tree<char> test;

			tree_node<char> * s1;
			tree_node<char> * s2;
			tree_node<char> * it;

			test.add('F', NULL);

			s1 = test.add('B', test.root);
			s2 = test.add('G', test.root);

			test.add('H', s2);
			test.add('I', s2->sons[0]);

			it = test.add('A', s1);
			test.add('X', it);
			test.add('D', s1);
			test.add('C', s1->sons[1]);
			test.add('E', s1->sons[1]);


			List <tree_node<char>*>* output;
			output = new List<tree_node<char>*>;

			test.postOrderIT(output);

			Assert::AreEqual(output->start->data->data, 'X');
			Assert::AreEqual(output->start->next->data->data, 'A');
			Assert::AreEqual(output->start->next->next->data->data, 'C');
			Assert::AreEqual(output->start->next->next->next->data->data, 'E');
			Assert::AreEqual(output->start->next->next->next->next->data->data, 'D');
			Assert::AreEqual(output->start->next->next->next->next->next->data->data, 'B');
			Assert::AreEqual(output->start->next->next->next->next->next->next->data->data, 'I');
			Assert::AreEqual(output->start->next->next->next->next->next->next->next->data->data, 'H');
			Assert::AreEqual(output->start->next->next->next->next->next->next->next->next->data->data, 'G');
			Assert::AreEqual(output->start->next->next->next->next->next->next->next->next->next->data->data, 'F');


		}

		TEST_METHOD(Tree_PostOrderREC)
		{
			Tree<char> test;

			tree_node<char> * s1;
			tree_node<char> * s2;


			test.add('F', NULL);

			s1 = test.add('B', test.root);
			s2 = test.add('G', test.root);

			test.add('H', s2);
			test.add('I', s2->sons[0]);

			test.add('A', s1);

			test.add('D', s1);
			test.add('C', s1->sons[1]);
			test.add('E', s1->sons[1]);


			List <tree_node<char>*>* output;
			output = new List<tree_node<char>*>;

			test.postOrderREC(output);

			Assert::AreEqual(output->start->data->data, 'A');
			Assert::AreEqual(output->start->next->data->data, 'C');
			Assert::AreEqual(output->start->next->next->data->data, 'E');
			Assert::AreEqual(output->start->next->next->next->data->data, 'D');
			Assert::AreEqual(output->start->next->next->next->next->data->data, 'B');
			Assert::AreEqual(output->start->next->next->next->next->next->data->data, 'I');
			Assert::AreEqual(output->start->next->next->next->next->next->next->data->data, 'H');
			Assert::AreEqual(output->start->next->next->next->next->next->next->next->data->data, 'G');
			Assert::AreEqual(output->start->next->next->next->next->next->next->next->next->data->data, 'F');

		}


		TEST_METHOD(Tree_PreOrderREC)
		{
			Tree<char> test;

			tree_node<char> * s1;
			tree_node<char> * s2;


			test.add('F', NULL);

			s1 = test.add('B', test.root);
			s2 = test.add('G', test.root);

			test.add('H', s2);
			test.add('I', s2->sons[0]);

			test.add('A', s1);
			test.add('D', s1);
			test.add('C', s1->sons[1]);
			test.add('E', s1->sons[1]);


			List <tree_node<char>*>* output;
			output = new List<tree_node<char>*>;

			test.PreOrderREC(output);

			Assert::AreEqual(output->start->data->data, 'F');
			Assert::AreEqual(output->start->next->data->data, 'B');
			Assert::AreEqual(output->start->next->next->data->data, 'A');
			Assert::AreEqual(output->start->next->next->next->data->data, 'D');
			Assert::AreEqual(output->start->next->next->next->next->data->data, 'C');
			Assert::AreEqual(output->start->next->next->next->next->next->data->data, 'E');
			Assert::AreEqual(output->start->next->next->next->next->next->next->data->data, 'G');
			Assert::AreEqual(output->start->next->next->next->next->next->next->next->data->data, 'H');
			Assert::AreEqual(output->start->next->next->next->next->next->next->next->next->data->data, 'I');

		}

		TEST_METHOD(Tree_PreOrderIT)
		{
			Tree<char> test;

			tree_node<char> * s1;
			tree_node<char> * s2;


			test.add('F', NULL);

			s1 = test.add('B', test.root);
			s2 = test.add('G', test.root);

			test.add('H', s2);
			test.add('I', s2->sons[0]);

			test.add('A', s1);
			test.add('D', s1);
			test.add('C', s1->sons[1]);
			test.add('E', s1->sons[1]);


			List <tree_node<char>*>* output;
			output = new List<tree_node<char>*>;

			test.preOrderIT(output);


			Assert::AreEqual(output->start->data->data, 'F');
			Assert::AreEqual(output->start->next->data->data, 'B');
			Assert::AreEqual(output->start->next->next->data->data, 'A');
			Assert::AreEqual(output->start->next->next->next->data->data, 'D');
			Assert::AreEqual(output->start->next->next->next->next->data->data, 'C');
			Assert::AreEqual(output->start->next->next->next->next->next->data->data, 'E');
			Assert::AreEqual(output->start->next->next->next->next->next->next->data->data, 'G');
			Assert::AreEqual(output->start->next->next->next->next->next->next->next->data->data, 'H');
			Assert::AreEqual(output->start->next->next->next->next->next->next->next->next->data->data, 'I');


		}

		TEST_METHOD(Tree_InOrderREC)
		{
			Tree<char> test;

			tree_node<char> * s1;
			tree_node<char> * s2;


			test.add('F', NULL);

			s1 = test.add('B', test.root);
			s2 = test.add('G', test.root);

			test.add('H', s2);
			test.add('I', s2->sons[0]);

			test.add('A', s1);
			test.add('D', s1);
			test.add('C', s1->sons[1]);
			test.add('E', s1->sons[1]);


			List <tree_node<char>*>* output;
			output = new List<tree_node<char>*>;

			test.InOrderREC(output);

			Assert::AreEqual(output->start->data->data, 'A');
			Assert::AreEqual(output->start->next->data->data, 'B');
			Assert::AreEqual(output->start->next->next->data->data, 'C');
			Assert::AreEqual(output->start->next->next->next->data->data, 'D');
			Assert::AreEqual(output->start->next->next->next->next->data->data, 'E');
			Assert::AreEqual(output->start->next->next->next->next->next->data->data, 'F');
			Assert::AreEqual(output->start->next->next->next->next->next->next->data->data, 'G');
			Assert::AreEqual(output->start->next->next->next->next->next->next->next->data->data, 'H');
			Assert::AreEqual(output->start->next->next->next->next->next->next->next->next->data->data, 'I');

		}

		TEST_METHOD(Tree_InOrderIT)
		{
		/*	Tree<char> test;

			tree_node<char> * s1;
			tree_node<char> * s2;


			test.add('F', NULL);

			s1 = test.add('B', test.root);
			s2 = test.add('G', test.root);

			test.add('H', s2);
			test.add('I', s2->sons[0]);

			test.add('A', s1);
			test.add('D', s1);
			test.add('C', s1->sons[1]);
			test.add('E', s1->sons[1]);


			List <char> output;
			

			test.InOrderIT(output);

			
			Assert::AreEqual(output[1] ,'A');
			Assert::AreEqual(output[2], 'B');
			Assert::AreEqual(output[3], 'C');
			Assert::AreEqual(output[4], 'D');
			Assert::AreEqual(output[5], 'E');
			Assert::AreEqual(output[6], 'F');
			Assert::AreEqual(output[7], 'G');
			Assert::AreEqual(output[8], 'H');
			Assert::AreEqual(output[9], 'I');

			/*Assert::AreEqual(output.start->next->data->data, 'B');
			Assert::AreEqual(output.start->next->next->data->data, 'C');
			Assert::AreEqual(output.start->next->next->next->data->data, 'D');
			Assert::AreEqual(output.start->next->next->next->next->data->data, 'E');
			Assert::AreEqual(output.start->next->next->next->next->next->data->data, 'F');
			Assert::AreEqual(output.start->next->next->next->next->next->next->data->data, 'I');
			Assert::AreEqual(output.start->next->next->next->next->next->next->next->data->data, 'H');
			Assert::AreEqual(output.start->next->next->next->next->next->next->next->next->data->data, 'G');*/
			Assert::IsTrue(false);
		}

		TEST_METHOD(Tree_TransversalOrder_IT)
		{


			Tree<char> test;

			tree_node<char> * s1;
			tree_node<char> * s2;

			test.add('F', NULL);

			s1 = test.add('B', test.root);
			s2 = test.add('G', test.root);

			test.add('H', s2);
			test.add('I', s2->sons[0]);

			test.add('A', s1);
			test.add('D', s1);
			test.add('C', s1->sons[1]);
			test.add('E', s1->sons[1]);

			List <tree_node<char>*> output;
			test.transversal_Order_IT(output);

			Assert::AreEqual(output.start->data->data, 'F');
			Assert::AreEqual(output.start->next->data->data, 'B');
			Assert::AreEqual(output.start->next->next->data->data, 'G');
			Assert::AreEqual(output.start->next->next->next->data->data, 'A');
			Assert::AreEqual(output.start->next->next->next->next->data->data, 'D');
			Assert::AreEqual(output.start->next->next->next->next->next->data->data, 'H');
			Assert::AreEqual(output.start->next->next->next->next->next->next->data->data, 'C');
			Assert::AreEqual(output.start->next->next->next->next->next->next->next->data->data, 'E');
			Assert::AreEqual(output.start->next->next->next->next->next->next->next->next->data->data, 'I');
		}
	};
}