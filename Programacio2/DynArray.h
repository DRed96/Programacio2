// ----------------------------------------------------
// Array that resizes dynamically   -------------------
// ----------------------------------------------------

#ifndef _DYNARRAY_H_
#define _DYNARRAY_H_

#define MEM_CHUNK 16
#include <assert.h>
#include "Swap.h"
#include <stdlib.h>
template<class TYPE>
class DynArray
{
public:
	TYPE*			data;
	unsigned int	memAlloc;
	unsigned int	nElements;

	// Constructors
	DynArray(): memAlloc(0), nElements(0), data(NULL)
	{
		Alloc(MEM_CHUNK);
	}

	DynArray(unsigned int newMem) : memAlloc(0), nElements(0), data(NULL)
	{
		Alloc(newMem);
	}

	// Destructor
	~DynArray()
	{
		delete[] data;
	}

	// Operators
	TYPE& operator[](unsigned int index)
	{
		assert(index < nElements);
		return data[index];
	}

	const TYPE& operator[](unsigned int index) const
	{
		assert(index < nElements);
		return data[index];
	}

	// Data Management
	void PushBack(const TYPE& element)
	{
		if (nElements >= memAlloc)
		{
			Alloc(memAlloc + MEM_CHUNK);
		}
		data[nElements++] = element;
	}

	bool Pop()
	{
		if (numElements > 0)
		{
			nElements--;
			return true;
		}
		return false;
	}

	bool Pop(TYPE& value)
	{
		if (num_elements > 0)
		{
			value = data[--nElements];
			return true;
		}
		return false;
	}

	void Clear()
	{
		nElements = 0;
	}

	bool Insert(const TYPE& element, unsigned int position)
	{
		if (position > nElements)
			return false;

		if (position == nElements)
		{
			PushBack(element);
			return true;
		}

		if (nElements + 1 > memAlloc)
			Alloc(memAlloc + MEM_CHUNK);

		for (unsigned int i = nElements; i > position; --i)
		{
			data[i] = data[i - 1];
		}

		data[position] = element;
		++nElements;

		return true;
	}

	TYPE* At(unsigned int index)
	{
		TYPE* result = NULL;

		if (index < nElements)
				result = &data[index];

		return result;
	}

	const TYPE* At(unsigned int index) const
	{
		TYPE* result = NULL;

		if (index < nElements)
			result = &data[index];

		return result;
	}

	// Utils
	unsigned int GetCapacity() const
	{
		return memAlloc;
	}

	unsigned int Count() const
	{
		return nElements;
	}

	void flip()
	{		
		for (unsigned int i = 0; i <= nElements / 2; i++)
		{
				swap(data[i], data[nElements - (i + 1)]);
				/*TYPE tmp = data[i];
				data[i] = data[nElements];
				data[nElements] = tmp;*/
		}
	
	}


private:

	// Private Utils
	void Alloc(unsigned int new_mem)
	{
		TYPE* tmp = data;

		memAlloc = new_mem;
		data = new TYPE [memAlloc];

		if (nElements > memAlloc)
				nElements = memAlloc;
		
	
		if (tmp != NULL)
		{
			for (unsigned int i = 0; i < nElements; i++)
			{
				data[i] = tmp[i];
			}

			delete[] tmp;
		}
	}
};

#endif // __DYNARRAY_H__