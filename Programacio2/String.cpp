#include <windows.h>
#include <stdio.h>
#include <stdarg.h>
#include "String.h"
#include <string.h>

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
	unsigned int nededSize = strlen(chain) + strlen(ref.chain) + 1;

	if (ref.size < nededSize)
	{
		char * tmp = ref.chain;
		ref.Alloc(nededSize);
		strcpy_s(ref.chain, ref.size, tmp);
	}
	strcat_s(ref.chain, nededSize, chain);

	Alloc(nededSize);
	strcpy_s(chain, nededSize, ref.chain);
}

void String::prefix(const char * input)
{
	if (input != NULL){
		unsigned int nededSize = strlen(chain) + strlen(input) + 1;

		String tmp(input);
		if (tmp.size < nededSize)
		{
			tmp.Alloc(nededSize);
			strcpy_s(tmp.chain, tmp.size, input);
		}
		strcat_s(tmp.chain, nededSize, chain);

		Alloc(nededSize);
		strcpy_s(chain, nededSize, tmp.chain);
	}
}

/* PROPOSTA COMPLEXA
Metode que faccountRsubstitució de cadenes
substitució(mundo, pepito)
hola pepito
*/

void String::Substitute(const char * original, const char * result)
{
	unsigned int pos;
	bool toSubstite = false;
	unsigned int  lenght = strlen(result);

	for (pos = 0; pos < lenght; ++pos, toSubstite = false)
	{
		for (unsigned int i = 0; original[i] == chain[pos + i], !toSubstite; i++)
		{
			if (i == lenght)
			{
				toSubstite = true;
			}
		}
		
		for (unsigned int i2 = 0; i2 < lenght; i2++)
		{
			chain[pos + i2] = result[i2];
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


//void Substitute()

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

		for (int i = 0; countR < len; i++, countR++)
		{
			chain[i] = chain[countR];
		}
		
		for (int i = len - countL; i < countL; i++)
		{
			chain[i] = toDestroy;
			len = i;
		}
}
//Operators

const bool String::operator == (const String & ref)
{
	return (strcmp(chain, ref.chain) == 0);
}

const bool String::operator == (const char * cpy)
{
	if (cpy != NULL) { return (strcmp(chain, cpy) == 0); }
	return false;
}

const bool String::operator != (const char * cpy)
{
	if (cpy != NULL) { return (strcmp(chain, cpy) != 0); }
	return false;
}

const bool String::operator != (const String & ref)
{
	return (strcmp(chain, ref.chain) != 0);
}

String & String::operator = (const String & ref)
{
	if (size < ref.size)
	{
		Alloc(ref.size);
	}
	strcpy_s(chain, size, ref.chain);
	len = ref.len;
	return (*this);
}

String & String::operator = (const char * cpyChain)
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
String & String::operator += (const String & ref)
{
	unsigned int finalSize = size + ref.size;
	if (size < finalSize)
	{
		char * tmp = chain;
		Alloc(finalSize);
		strcpy_s(chain, size, tmp);
	}
	strcat_s(chain, size, ref.chain);

	return (*this);
}

String & String::operator += (const char * cpyChain)
{
	if (cpyChain != NULL)
	{
		unsigned int finalSize = size + strlen(cpyChain) + 1;
		if (size < finalSize)
		{
			char * tmp = chain;
			Alloc(finalSize);
			strcpy_s(chain, size, tmp);
		}
		strcat_s(chain, size, cpyChain);
	}
	return (*this);
}