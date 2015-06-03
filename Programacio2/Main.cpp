#include <stdio.h>
#include "List.h"
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
	List<int> t1;
	t1.Add(25);
	t1.Add(9);
	t1.Add(42);


	t1.swapNodes(t1.start, t1.start->next);

	for (unsigned int i = 0; i < t1.size; i++)
		printf("Postion %d == %d \n", i, t1[i]);

	getchar();
	return 0;
}