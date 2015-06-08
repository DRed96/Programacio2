#include <stdio.h>
#include "Queue_List.h"
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
	Queue_List<int> fifo;


	fifo.PushBack(11);
	fifo.PushBack(22);
	fifo.PushBack(33);

	int ref;

	fifo.PopFirst(ref);
	printf("ref == %d", ref);
	fifo.PopFirst(ref);
	printf("ref == %d", ref);
	fifo.PopFirst(ref);
	printf("ref == %d", ref);
	fifo.PopFirst(ref);
	printf("ref == %d", ref);
	getchar();
	return 0;
}



