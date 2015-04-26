#define MEM_CHUNK 16
template <class T>
class Stack{
private:
	unsigned int nElements; //Cambiar el tipus segons l'utilització de la cadena
	unsigned int mem_alloc;// Quantitat de memòria	

public:
	
	T * data;
	//Constructors
	Stack() : mem_alloc(0), data(NULL), nElements(0)
	{
		//mem_alloc = 0; data = NULL; nElements = 0;
	}
	Stack(unsigned int Size): mem_alloc(Size), nElements(0)
	{
		data = new T[mem_alloc];
	}


	//Destructor
	~Stack()
	{
		if (data != NULL){
			delete[]data;
		}
	}

	//Getters

	unsigned int getMem() const { return mem_alloc; }
	unsigned int getElem() const { return nElements; }
	//Methods
	void PushBack(const T newValue){
		if (data != NULL)
		{
			if (nElements >= mem_alloc)
			{
				T * tmpCpy = data;
				mem_alloc++;
				data = new T[mem_alloc];
				CopyArrays(data, tmpCpy, nElements);
				delete[] tmpCpy;
			}

			data[nElements] = newValue;
			nElements++;
		}
		else
		{
			nElements = 1;
			mem_alloc = 1;
			data = new T[mem_alloc];
			data[0] = newValue;

		}
	}

	T* Pop()
	{
		if (nElements != 0)
		{
			int * ret;
			nElements--;
			ret =data[nElements];
			return ret;
		}
		return NULL;
		//If it does nothing, it returns 0
	}
	
	//Gets a pointer to the top of the stack 
	T& Top()
	{
		return data[nElements];
	}

	void CopyArrays(T * destiny, T * source, unsigned int newMem)
	{
		if (source != NULL)
		{
			if (destiny == NULL)
			{
				destiny = new T[newMem];
			}
			for (unsigned int i = 0; i < newMem; i++)
			{
				destiny[i] = source[i];
			}

		}

	}

};