#include <stdio.h>
#include "String.h"
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
	String t1("    Hola mundo      ");//4 esquerra, 6 dreta
	t1.Trim(true, true, ' ');
	printf("Mem == %d \n", t1.getSize());
	for (unsigned int i = 0; i < t1.getSize(); i++)
	{
		

		printf("Len == %d \n", t1.getLen());
		printf("Pos == %d \n",i);
		printf("Data  == %c \n", t1.chain[i]);
		printf("---------------------------\n");
		
	}

	getchar();
	return 0;
}



