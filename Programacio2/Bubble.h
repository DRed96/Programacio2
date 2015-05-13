#include "RICARRAY.h"

/*
void BubbleSort()
{
	while ( swaped)
	for (int i = 0; i < n_Elements - 1; i++)
	{
		if (data[i] > data[i + 1])
			swap(data[i], data[i + 1]);
		swaped = false
	}
}
*/


int Bubble(p2DynArray <int>* toOrder)
{
	int i = 0;
	int j = i + 1;
	int checker = 0;
	bool ret = true;
	while (ret)
	{
		ret = false;
		for (i = 0; i < toOrder->num_elements - 1 ; i++)
		{
			checker++;
			if (toOrder->data[i] > toOrder->data[i + 1])
			{
				int tmp = toOrder->data[i];
				toOrder->data[i] = toOrder->data[i + 1];
				toOrder->data[i + 1] = tmp;
				ret = true;
			}

		}
	}
	return checker;
}
