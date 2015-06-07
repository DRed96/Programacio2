#include <assert.h>
#define MEM_CHUNK 16

template <class T>
class Queue{
private:
	T * data;
	unsigned int nElements; //Cambiar el tipus segons l'utilització de la cadena
	unsigned int mem_alloc;// Quantitat de memòria	
	unsigned int start_pos;


public:
	//Constructor
	Queue()
	{
		mem_alloc = 0; data = NULL; nElements = 0; start_pos = 0;
	}

	~Queue(){ if (data != NULL) delete[] data; }

	//Getters
	unsigned int getMem() const { return mem_alloc; }
	unsigned int getElem() const { return nElements; }

	const T & getStart() const
	{
		return data[start_pos];
	}
	const T &  getTop() const
	{
		return data[nElements - 1];
	}


	//Methods
	void PushBack(const T& newValue){
		if (data != NULL)
		{
			//if (nElements < start_pos){ nElements = start_pos; }

			
		/*	if (nElements + start_pos >= mem_alloc)
			{
				if (nElements == 0)
				{

				}

				
			}*/
			

			
			if (nElements + start_pos >= mem_alloc)
			{
				 T * tmpCpy = data;

				if (nElements >= mem_alloc)
				{
					mem_alloc += MEM_CHUNK;
					data = new T[mem_alloc];
				}

				else
				{

					data = new T[mem_alloc];

				}

				for (unsigned int i = 0; i < mem_alloc; i++)
				{
					data[i] = tmpCpy[start_pos + i];
				}
				start_pos = 0;
				delete[] tmpCpy;
			}
			data[start_pos + nElements++] = newValue;
		}

		else
		{
			nElements = 1;
			mem_alloc = MEM_CHUNK;
			start_pos = 0;
			data = new T[mem_alloc];
			data[0] = newValue;

		}
	}

	/*void PopFirst(){
		if (start_pos < mem_alloc)
			start_pos++;
			nElements--;
	}*/

	bool PopFirst(T& ref){
		ref = NULL;
		if (start_pos < mem_alloc)
			{
			ref = data[start_pos];
				start_pos++; 
				nElements--;
				return true;
			}
		else
		return false;
	}

	void CopyArrays(int * destiny, int * source, unsigned int newMem)
	{
		if (source != NULL)
		{
			if (destiny == NULL)
			{
				destiny = new int[newMem];
			}
			for (unsigned int i = 0; i < newMem; i++)
			{
				destiny[i] = source[i];
			}

		}
	}

	//Operator
	const T & operator [] (unsigned int index) const {
		assert(index < nElements);
		return data[index];
	}
};