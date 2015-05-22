#pragma once
#include "List.h"
template <class T>
class Stack_List
{
public:
	List  <T> data;

	unsigned int nElements; //Cambiar el tipus segons l'utilització de la cadena
	unsigned int mem_alloc;// Quantitat de memòria	

	Stack_List() : mem_alloc(0), , nElements(0), isOver(false)
	{
		//mem_alloc = 0; data = NULL; nElements = 0;
		data.start = NULL;
	}

	void PushBack(const T& newValue)
	{
		data.Add(T);
		nElements++;
		if (nElements > mem_alloc)
			mem_alloc++;
	}

	bool Pop()
	{
		if (nElements != 0)
		{
			nElements--;
			data.del(data.end);
			return true;
		}
		return false;
	}

	T& Peek(unsigned int index) const
	{
		T* ret = NULL;
		if (index < nElements)
		{
			ret = &data[index];
		}
			
		return ret;
	}
};