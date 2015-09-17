#include <stdio.h>
#include "List.h"
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

	List <int> l1;
	DynArray <int> *ptr = NULL;

	for (int i = 0; i <= 15; i++)
		l1.add(i);
	ptr = new DynArray<int>;
	l1.copyToArray(ptr);

	ptr->~DynArray();
	l1.copyToArray(ptr);

	for (int j = 0; j < 15; j++)
	{
		//Assert::AreEqual(ptr->operator[](j), l1[j]);
		//Assert::AreEqual(ptr->operator[](j), j);
		printf("ARRAY PTR: %i SHOULD BE: %i  \n", ptr->operator[](j), j);
	}

	getchar();
	return 0;
}


