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
	List <int> t1;
	List <int> t2;

	for (int i = 0; i < 2; i++)
		t1.Add(i);

	t2.Add(-1);
	t2.Add(-2);
	t2.Add(-3);
	
	t1 += t2;

	for (unsigned int i = 0; i < t1.size; i++){
		int debug = t1[i];
		printf("Postion %d == %d \n", i, t1[i]);
		
	}

	getchar();
	return 0;
}
//-		((t1).start)->next	0x00b93ae0 {data=1 next=0x00b97240 {data=-17891602 next=0xfeeefeee {data=??? next=??? prev=??? } prev=...} ...}	node<int> *
//+		next	0x00b97240 {data=-17891602 next=0xfeeefeee {data=??? next=??? prev=??? } prev=0xfeeefeee {data=??? next=...} }	node<int> *
