#define MEM_CHUNK 16
template <class T>
class Stack{
public:
	unsigned int nElements; //Cambiar el tipus segons l'utilització de la cadena
	unsigned int mem_alloc;// Quantitat de memòria	


	T * data;
	bool isOver;
	
public:
	//Constructors
	Stack() : mem_alloc(0), data(NULL), nElements(0), isOver(false)
	{
		//mem_alloc = 0; data = NULL; nElements = 0;
	}
	Stack(unsigned int Size) : mem_alloc(Size), nElements(0), isOver(false)
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
	void PushBack(const T& newValue){
		if (data != NULL)
		{
			if (nElements >= mem_alloc)
			{
				T * tmpCpy = data;
				mem_alloc += MEM_CHUNK;
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

	bool Pop(T& reference)
	{
		if (nElements != 0){
			nElements--;
			reference = data[nElements];
				return true;
		}
		else
		
			return false;	
	}
	
	bool Pop()
	{
		if (nElements != 0){
			nElements--;
			data[nElements];
			return true;
		}
		else

			return false;
	}
	//Gets a pointer to the top of the stack 
	bool Top(T& reference)
	{
		if (nElements != 0)
		{
			reference = data[nElements - 1];
			return true;
		}
		return false;
	

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