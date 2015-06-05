
#include "String.h"


#define TMP_STRING_SIZE	4096
//Constructors
String::String()
{
	Alloc(1);
	Clear();
	len = 0;
}

String::String(unsigned int newSize)
{
	Alloc(newSize);
	Clear();
	len = 0;
}
String::String(const char * cpy, ...)
{
	//CodcountRfet per Ricard
	//--------------------------------------
	size = 0;
	if (cpy != NULL)
	{
		static va_list args;
		static char tmp[TMP_STRING_SIZE];

		va_start(args, cpy);

		int nSize = vsnprintf_s(tmp, TMP_STRING_SIZE, cpy, args);
		va_end(args);

		if (nSize > 0)
		{
			Alloc(nSize + 1);
			strcpy_s(chain, size, tmp);
			len = strlen(chain)- 1;
		}
	}
	if (size == 0)
	{
		Alloc(1);
		Clear();
	}
	//--------------------------------------
}

String::String(const String & ref)
{
	len = strlen(ref.chain) - 1;
	size = ref.size;
	chain = new char[size];
	strcpy_s(chain, size, ref.chain);
}

//Destructor
String::~String(){ delete[] chain; }

//Utils
void String::Clear()
{
	chain[0] = '\0';
	len = 0;
}
unsigned int String::getLen()
{
	len = strlen(chain);
	return len;

}
unsigned int String::getSize() const
{
	return size;
}
const char* String::getString() const
{
	return chain;
}
//Methods

void String::prefix(String  ref)
{
	unsigned int neededSize = strlen(chain) + strlen(ref.chain) + 1;

	if (ref.size < neededSize)
	{
		char * tmp = ref.chain;
		ref.Reallocate(neededSize);
		strcpy_s(ref.chain, ref.size, tmp);
		delete[] tmp;
	}
	strcat_s(ref.chain, neededSize, chain);

	Alloc(neededSize);
	strcpy_s(chain, neededSize, ref.chain);
}

void String::prefix(const char * input)
{
	if (input != NULL){
		unsigned int neededSize = strlen(chain) + strlen(input) + 1;

		String tmp(input);
		if (tmp.size < neededSize)
		{
			Reallocate(neededSize);
		}
		strcat_s(tmp.chain, neededSize, chain);

		Alloc(neededSize);
		strcpy_s(chain, neededSize, tmp.chain);
	}
}

/* PROPOSTA COMPLEXA
Metode que faccountRsubstitució de cadenes
substitució(mundo, pepito)
hola pepito
*/


// Substitute amb metodes petits
// diferencia de tamany
void String::Find(const char * original, Queue<unsigned int>& ref)
{

	assert(ref.getElem() == 0);
	unsigned int pos = 0, counter = 1;
	unsigned int lenght = strlen(original);
	while (pos <= len - lenght + 1)
	{
		if (original[0] == chain[pos])
		{
			for (unsigned int i = 1; i < len && original[i] == chain[pos + i]; i++, counter++)
			{}		
			if (counter == lenght)
			{
				ref.PushBack(pos);
				pos += lenght - 1;
			}
		}
		counter = 1;
		pos++;
	}
}

void  String::PrepareString(const Queue<unsigned int>& ref)
{
	
}


void String::Substitute(const char * original, const char * result)
{
	unsigned int pos;
	bool toSubstite = false;
	unsigned int  lenght = strlen(result);
	int diff = lenght - strlen(original);

	//Queue <unsigned int> & matches = Find(original);
	
//	int neded_mem = matches.getElem() * diff;

/*	if (neded_mem > 0)
	{
		//chain 
	}*/
	

	/*Find
	Prepare
	Substitute*/

	Queue <unsigned int> calls;
	// Fer mètode que busqui quantes vegades hi ha X paraula dins una cadena 
	for (pos = 0; pos < len; ++pos, toSubstite = false)
	{
		if (original[0] == chain[pos])
		{

			for (unsigned int i = 1; original[i] == chain[pos + i], !toSubstite; i++)
			{
				if (i == lenght)
				{
					toSubstite = true;
				}
			}
			for (pos = 0; pos < len; ++pos, toSubstite = false)
			{
				for (unsigned int i2 = 0; i2 < lenght; i2++, pos++)
				{
					chain[pos] = result[i2];
				}
				//Pos is now at the end of the substituted word
				
			}

		}
		unsigned int positions = 0;
		unsigned int cicles = 1;
		if (diff < 0)
		{
			while (calls.getElem() >= 0)

			{
				unsigned int positions_2 = calls.getStart();


				for (unsigned int i3 = positions; i3 < positions - diff && i3 < positions_2 - cicles - 1; i3++)
				{
					chain[i3] = chain[i3 + 1];
				}


				cicles++;
			}
		}
	}
}

// TODO: Proposta, trim amb arguments molt cool countRque estigucountRoptimitzat, if you feel like it
/*void String::OLD_Trim()
{
	unsigned int countR= 0;
	for (; countR< len && chain[i] == ' '; i++)
	{	}

	unsigned int j = len - 1;

	for (; j > 0 && chain[j] == ' '; j--)
	{	}

	char * tmp = new char[j - i];
	for (int x1 = 0; countR< j; x1++, i++)
	{
		tmp[x1] = chain[i];
	}
	delete chain;
	chain = tmp;
	len = j - i;
	size = len + 1;
}*/

//Funcio que mircountRels espais
void String::Trim2()
{
	///Counters NO-OPTIMAL
	unsigned int countR;
	unsigned int countL;
	unsigned int i;

	//Count spaces starting from the begging
	for (countR = 0; chain[countR] == ' '; countR++)
	{}

	//Count spaces starting from the end
	for (countL = len; chain[countL] == ' '; --countL)
	{}
	//Puts letters to the start
	for (i = 0; countR < len && i <= countL; i++, countR++)
	{
		chain[i] = chain[countR];
	}
	len = i;
	chain[i] = '\0';
}



void String::Trim(bool toRight, bool toLeft, char toDestroy)
{
	unsigned int countR, countL = 0;
	
		for (int countL = len; countL > 0 && chain[countL] != toDestroy; countL++)
		{
			countL;
		}
	
		if (toRight)
		{
			for (countR = 0; countR < len && chain[countR] != toDestroy; countR++){}
		}

		for (unsigned int i = 0; countR < len; i++, countR++)
		{
			chain[i] = chain[countR];
		}
		
		for (unsigned int i2 = len - countL; i2 < countL; i2++)
		{
			chain[i2] = toDestroy;
			len = i2;
		}
}
//Operators

//Change the memory of the string, keeping the data
void String::Reallocate(const unsigned int newMem)
{
	if (newMem > size)
	{
		char * tmp = chain;
		chain = new char[newMem];
		strcpy_s(chain, size, tmp);
		size = newMem;
		delete[] tmp;
	}
	else
	{
		chain[newMem] = '\0';
		size = newMem;
	}
}

bool String::operator == (const String & ref)
{
	return (strcmp(chain, ref.chain) == 0);
}

bool String::operator == (const char * cpy)
{
	if (cpy != NULL) { return (strcmp(chain, cpy) == 0); }
	return false;
}

bool String::operator != (const char * cpy)
{
	if (cpy != NULL) { return (strcmp(chain, cpy) != 0); }
	return false;
}

bool String::operator != (const String & ref)
{
	return (strcmp(chain, ref.chain) != 0);
}

const String & String::operator = (const String & ref)
{
	if (size < ref.size)
	{
		delete[] chain;
		Alloc(ref.size);
	}
	strcpy_s(chain, size, ref.chain);
	len = ref.len;
	return (*this);
}

const String & String::operator = (const char * cpyChain)
{
	unsigned int needSize = strlen(cpyChain) + 1;
	if (cpyChain != NULL)
	{
		if (size < needSize)
		{
			delete[] chain;
			Alloc(needSize);
		}
		strcpy_s(chain, size, cpyChain);
		len = strlen(chain);
	}
	else
	{
		Clear();
		len = 0;
	}
	return (*this);
}
const String & String::operator += (const String & ref)
{
	unsigned int finalSize = size + ref.size;
	
	if (size < finalSize)
	{
		char * tmp = chain;
		Alloc(finalSize);
		strcpy_s(chain, size, tmp);
		delete[] tmp;

	}
	
	strcat_s(chain, size, ref.chain);

	return (*this); //Contingut del punter
}

const String & String::operator += (const char * cpyChain)
{
	if (cpyChain != NULL)
	{
		unsigned int finalSize = size + strlen(cpyChain) + 1;
		if (size < finalSize)
		{
			char * tmp = chain;
			Alloc(finalSize);
			strcpy_s(chain, size, tmp);
			delete[] tmp;

		}
		strcat_s(chain, size, cpyChain);
	}
	return (*this);
}