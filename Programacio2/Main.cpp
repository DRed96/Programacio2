#include <stdio.h>
#include "Queue_Array.h"
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
	Queue_Array <int> t1;
	

	

//	t1.PushBack(0);
	

for (unsigned int i = 0; i < 99; i++)
	{
		t1.PushBack(i);
		printf("Elements == %d \n", t1.get_Elements());
		printf("Mem == %d \n", t1.get_Memory());
		printf("Data  == %d \n", t1[i]);
		
	}

	getchar();
	return 0;
}



