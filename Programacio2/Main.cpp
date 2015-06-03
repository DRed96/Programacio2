#include "DynArray.h"
#include <stdio.h>
#include "String.h"
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
	String test("hola mundo hola mundo mundo hola hol mun mundo");
	Queue<unsigned int> t1;
	test.Find("mun", t1);
	
	printf("Similarities found == %d", t1.getElem());
	getchar();
	return 0;
}