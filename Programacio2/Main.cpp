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

	Tree<int> tree;
	//He vist que el meu Add funciona amb un punter com a argument
	//En la meva classe, el node root no esta suposat que tingui cap valor
	tree_node<int> * iterative;
	tree_node<int> * s1;
	tree_node<int> * s2;
	iterative = tree.Add(1, NULL);


	s1 = tree.Add(2, iterative);
	tree.Add(3, iterative);
	s2 = tree.Add(4, iterative);

	tree.Add(5, s1);
	tree.Add(6, s1);
	tree.Add(7, s1);

	tree.Add(8, s2);
	iterative = tree.Add(9, s2);

	tree.Add(10, iterative);

	tree.CalcAdditionIterative();
	//printf("ref == %d", ref);
	getchar();
	return 0;
}


