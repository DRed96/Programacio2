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
	int debug;
	String s1("Hola mundo");
	s1.Cut(2, 5);
	debug = strcmp("Houndo", s1.getString());
	s1.Cut(3, 0);
	debug = strcmp("Hou", s1.getString());
	//printf("ref == %d", ref);
	getchar();
	return 0;
}


