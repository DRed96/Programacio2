// ----------------------------------------------------
// Array that resizes dynamically   -------------------
// ----------------------------------------------------

#ifndef _DYNARRAY_H_
#define _DYNARRAY_H_

#define MEM_CHUNK 16
#include <assert.h>
#include <stdlib.h>
#include "Utils.h"
#include "List.h"

template<class TYPE>
class DynArray
{
public:
	TYPE*			data;
	unsigned int	memalloc;
	unsigned int	nElements;

	// Constructors
	DynArray(): memalloc(0), nElements(0), data(NULL)
	{
		alloc(MEM_CHUNK);
	}

	DynArray(unsigned int newMem) : memalloc(0), nElements(0), data(NULL)
	{
		alloc(newMem);
	}

	// Destructor
	~DynArray()
	{
		delete[] data;
		data = NULL;
		memalloc = nElements = 0;
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

	/*unsigned int finalSize = size + ref.size;
	
	if (size < finalSize)
	{
		char * tmp = chain;
		alloc(finalSize);
		strcpy_s(chain, size, tmp);
		delete[] tmp;

	}
	
	strcat_s(chain, size, ref.chain);*/

	DynArray& operator +=(const DynArray<TYPE>& toCpy)
	{
		unsigned int finalSize = nElements + toCpy.nElements;

		alloc(finalSize);
		for (unsigned int i = 0; i < toCpy.nElements; i++)
		{
			data[nElements + i] = toCpy[i];
		}
		nElements = finalSize;
		return(*this);
	}

	// Data Management
	void PushBack(const TYPE& element)
	{
		if (nElements >= memalloc)
		{
			alloc(memalloc + MEM_CHUNK);
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

		if (nElements + 1 > memalloc)
			alloc(memalloc + MEM_CHUNK);

		for (unsigned int i = nElements; i > position; --i)
		{
			data[i] = data[i - 1];
		}

		data[position] = element;
		++nElements;

		return true;
	}


	bool Insert_Array(const DynArray& toInsert, unsigned int position)
	{
		unsigned int needed_mem = toInsert.nElements + nElements;
		if (position > memalloc)
			return false;

		if (memalloc < needed_mem)
		{
			alloc(needed_mem);
		
			for (unsigned int i2 = 0, i = nElements - 1; i >= position; i--, i2++)
			{
				data[memalloc - i2 - 1] = data[i];
			}
		}
		else
		{
			for (unsigned int i2 = 0, i = nElements - 1; i >= position; i--, i2++)
			{
				data[needed_mem - i2 - 1] = data[i];
			}
		}
		for (unsigned int i = 0; i < toInsert.nElements; i++)
		{
			data[position + i] = toInsert[i];
			nElements++;
		}
		//for (i)
		//data [i + toInsert.nElements] = data [i
		//data[i] = toInsert[i - position]

		return true;
	}


	TYPE* At(unsigned int index)
	{
		TYPE* result = NULL;

		if (index < nElements)
				result = &data[index];

		return result;
	}

	const TYPE* at(unsigned int index) const
	{
		TYPE* result = NULL;

		if (index < nElements)
			result = &data[index];

		return result;
	}

	// Utils
	unsigned int getCapacity() const
	{
		return memalloc;
	}

	unsigned int count() const
	{
		return nElements;
	}

	void flip()
	{		
		for (unsigned int i = 0; i < nElements / 2; i++)
		{
				swap(data[i], data[nElements - (i +1)]);
			
		}
	
	}

	bool copyToList(List<TYPE> * toFill)
	{
		bool success = true;
		//toFill == NULL ||
		if (toFill != NULL && toFill->size == 0 )
		{
			for (unsigned int i = 0; i < nElements; i++)
			{
				toFill->add(this->operator[](i));
			}	
		}
		else
		{
			success = false;
		}
		return success;
	}

private:

	// Private Utils
	void alloc(unsigned int new_mem)
	{
		TYPE* tmp = data;

		memalloc = new_mem;
		data = new TYPE [memalloc];

		if (nElements > memalloc)
				nElements = memalloc;
		
	
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