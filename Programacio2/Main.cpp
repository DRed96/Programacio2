#include "DynArray.h"
#include <stdio.h>
#include "DynArray.h"
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
	DynArray<int> t1;
	DynArray<int> t2;
	for (int i = 1; i < 6; i++)
	{
		t1.PushBack(i);

	}

	t2.PushBack(-1);
	t2.PushBack(-2);
	t2.PushBack(-3);


	t1.Insert(t2, 3);

	for (int i = 0; i < t1.nElements; i++)
		printf("Postion %d == %d \n", i, t1[i]);

	getchar();
	return 0;
}