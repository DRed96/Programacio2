#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Programacio2/Tree.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(TreeTests)
	{
	public:

		TEST_METHOD(Tree_Add)
		{
			Tree<int> test;
			//OPERATOR?
			tree_node<int> * s1;
			tree_node<int> * s2;
			tree_node<int> * it; //ITERATIVE NODE
			test.Add(9, NULL);

			s1 = test.Add(11, test.root);
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

		TEST_METHOD(Tree_Clear)
		{
			Tree<char> test;
			tree_node <char>* a;
			a = test.Add('A');
			tree_node<char>* b;
			b = test.Add('B', a);
			tree_node<char>* c;
			c = test.Add('C', a);

			Assert::AreEqual(test.root->data, 'A');

			List <tree_node<int>*> output;
			test.Clear();
			Assert::IsTrue(output.size == 0);

			Assert::AreEqual(test.root->sons.size, (unsigned int)0);
		}


		TEST_METHOD(Tree_Clear_2)
		{
			Tree<char> test;
			test.Add('F', NULL);

			tree_node<char> * s1;
			tree_node<char> * s2;
			s1 = test.Add('B', test.root);
			s2 = test.Add('G', test.root);

			test.Add('H', s2);
			test.Add('I', s2->sons[0]);

			test.Add('A', s1);
			test.Add('D', s1);

			test.Add('C', s1->sons[1]);
			test.Add('E', s1->sons[1]);

			Assert::AreEqual(test.root->data, 'F');

			List <tree_node<int>*> output;
			test.Clear(s1->sons[1]);

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

			test.Add('F', NULL);

			s1 = test.Add('B', test.root);
			s2 = test.Add('G', test.root);

			test.Add('H', s2);
			test.Add('I', s2->sons[0]);

			it = test.Add('A', s1);
			test.Add('X', it);
			test.Add('D', s1);
			test.Add('C', s1->sons[1]);
			test.Add('E', s1->sons[1]);


			List <tree_node<char>*>* output;
			output = new List<tree_node<char>*>;

			test.PostOrderIT(output);

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


			test.Add('F', NULL);

			s1 = test.Add('B', test.root);
			s2 = test.Add('G', test.root);

			test.Add('H', s2);
			test.Add('I', s2->sons[0]);

			test.Add('A', s1);

			test.Add('D', s1);
			test.Add('C', s1->sons[1]);
			test.Add('E', s1->sons[1]);


			List <tree_node<char>*>* output;
			output = new List<tree_node<char>*>;

			test.PostOrderREC(output);

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


			test.Add('F', NULL);

			s1 = test.Add('B', test.root);
			s2 = test.Add('G', test.root);

			test.Add('H', s2);
			test.Add('I', s2->sons[0]);

			test.Add('A', s1);
			test.Add('D', s1);
			test.Add('C', s1->sons[1]);
			test.Add('E', s1->sons[1]);


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


			test.Add('F', NULL);

			s1 = test.Add('B', test.root);
			s2 = test.Add('G', test.root);

			test.Add('H', s2);
			test.Add('I', s2->sons[0]);

			test.Add('A', s1);
			test.Add('D', s1);
			test.Add('C', s1->sons[1]);
			test.Add('E', s1->sons[1]);


			List <tree_node<char>*>* output;
			output = new List<tree_node<char>*>;

			test.PreOrderIT(output);


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


			test.Add('F', NULL);

			s1 = test.Add('B', test.root);
			s2 = test.Add('G', test.root);

			test.Add('H', s2);
			test.Add('I', s2->sons[0]);

			test.Add('A', s1);
			test.Add('D', s1);
			test.Add('C', s1->sons[1]);
			test.Add('E', s1->sons[1]);


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


			test.Add('F', NULL);

			s1 = test.Add('B', test.root);
			s2 = test.Add('G', test.root);

			test.Add('H', s2);
			test.Add('I', s2->sons[0]);

			test.Add('A', s1);
			test.Add('D', s1);
			test.Add('C', s1->sons[1]);
			test.Add('E', s1->sons[1]);


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

			test.Add('F', NULL);

			s1 = test.Add('B', test.root);
			s2 = test.Add('G', test.root);

			test.Add('H', s2);
			test.Add('I', s2->sons[0]);

			test.Add('A', s1);
			test.Add('D', s1);
			test.Add('C', s1->sons[1]);
			test.Add('E', s1->sons[1]);

			List <tree_node<char>*> output;
			test.Transversal_Order_IT(output);

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