#ifndef _QUEUE_ARRAY_H_
#define _QUEUE_ARRAY_H_

#include "DynArray.h"
#define MEM_CHUNK 16
#define OPTIM_LIMIT 5
template<class T>
class Queue_Array{

	
	unsigned int start_pos;
	unsigned int nElements;
	unsigned int mem_alloc;

public:


	T * data;

	Queue_Array() : start_pos(0), nElements(0), mem_alloc(MEM_CHUNK)
	{
		data = new T[MEM_CHUNK];
	}

	//Destructor?

	//Getters
	unsigned int get_Start_Pos() const{ return start_pos; }
	unsigned int get_Elements() const{ return nElements; }
	unsigned int get_Memory() const{ return mem_alloc; }

	//Methods
	void PushBack(const T & element)
	{
		
		if (start_pos + nElements > mem_alloc)
		{
			if (start_pos >= OPTIM_LIMIT)
			{
				Trim_Queue();
			}
			else
			{
				T * tmp = data;
				data = new T[mem_alloc + MEM_CHUNK];
					//Copy the contents of both arrays
					for (unsigned int i = 0; i < nElements; i++)
					{
						data[i] = tmp[start_pos + nElements];
					}
				mem_alloc += MEM_CHUNK;
				delete[] tmp;
			}
		}
		data[start_pos + nElements++] = element;
	}
		
	void Trim_Queue()
	{
		if (data)
			for (unsigned int i = 0; i >= start_pos; i++)
			{
				data[i] = data[start_pos - i];
			}
			start_pos = 0;
	}

	bool PopFirst(T & ref)
	{
		if (nElments == 0)
			return false;
		else
		{
			ref = data[start_pos++];
			nElements--;
		}

		if (start_pos >= mem_alloc && nElements == 0)
		{
			start_pos = 0;
		}

		return true;
		
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