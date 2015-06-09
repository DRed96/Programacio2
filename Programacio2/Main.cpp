#include <stdio.h>
#include "DynArray.h"
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

	//printf("ref == %d", ref);
	getchar();
	return 0;
}



