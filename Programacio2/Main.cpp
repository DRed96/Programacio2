#include <stdio.h>
#include "Tree.h"
#include "Utils.h"
/*

int fibonacci(unsigned int index)
{
	int first = 0;
	int second = 1;
	int ret = 0;

	for (unsigned int i = 0; i < index; i++)
	{
		ret = second + first;
		first = second;
		second = ret;
	}
	return ret;
}
*/
/**
*Fer fibonacci iteratiu i recursiu
**/

/*
int fibonaci_iterative(unsigned int position)
{
	if (position == 1 || position == 0)
		return 1
	else
	return fibonacci(pos - 1) + fibonacci()
}*/


int main()
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
	//output = new List<tree_node<char>*>;

	test.Transversal_Order_IT(output);

	for (unsigned int i = 0; i < output.count(); i++)
	{
		printf("Postion %d == %c \n", i, output[i]->data);
	}

	getchar();
	return 0;
}


/*
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
output = new List < tree_node<char>* >;

test.PreOrderIT(output);
//LOG("----------- %c", output->start->data->data);

//-		((t1).start)->next	0x00b93ae0 {data=1 next=0x00b97240 {data=-17891602 next=0xfeeefeee {data=??? next=??? prev=??? } prev=...} ...}	node<int> *
//+		next	0x00b97240 {data=-17891602 next=0xfeeefeee {data=??? next=??? prev=??? } prev=0xfeeefeee {data=??? next=...} }	node<int> *
*/