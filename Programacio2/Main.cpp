#include "List.h"
#include <stdio.h>
#include "log.h"
int main()
{
	List<int> test;
	
	for (unsigned int i = 0; i < 10000; i++)
	{
		
		test.Add(rand() % 10000);
	}

	LOG("Iterations = %d \n", test.BubbleSort());
}