#ifndef _QUEUE_ARRAY_H_
#define _QUEUE_ARRAY_H_

#include "DynArray.h"
#define MEM_CHUNK 16
#define OPTIM_LIMIT 7
template<class T>
class Queue_Array{
	unsigned int start_pos;
	unsigned int nElements;
	unsigned int mem_alloc;
	T * data;
public:

	Queue_Array() : start_pos(0), nElements(0), mem_alloc(0)
	{}

	void Push(const T element)
	{
		if (start_pos + nElements > mem_alloc)
			if (start_pos >= OPTIM_LIMIT)
			{
				Trim_Queue();
			}
			else
			{
				T * tmp = data;
				
				data = new T[mem_alloc + MEM_CHUNK]
					for (unsigned int i = 0; i < nElements; i++)
					{
						data[i] = tmp[start_pos + nElements];
					}
				mem_alloc += MEM_CHUNK;
			}


	}

	void Trim_Queue()
	{
		for (unsigned int i = 0; i >= start_pos; i++)
		{
			data[i] == data[start_pos - i];
		}
		start_pos == 0;
	}

	/*
	Constructors i destructors
	-Push
	PopFirst
	Peek?
	Operator []?
	*/



};


#endif /*_QUEUE_ARRAY_H_*/