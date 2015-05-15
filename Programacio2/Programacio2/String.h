#ifndef _STRING_H_
#define _STRING_H_

#include <string.h>
class String{
public:
	char * chain;
	unsigned int len;
	unsigned int size;

	//POSAR GETTERS I FER PRIVAT?
	String();

	String(unsigned inta);

	String(const char * cpy, ...);

	String(const String & ref);


	~String();

	//Utils
	void Clear();
	unsigned int getLen();
	unsigned int getSize() const;

	const char* getString() const;
	//Methods
	void prefix(String ref);

	void prefix(const char * ref);
	//Operators

	const bool operator == (const String & ref);

	const bool operator == (const char * cpy);

	const bool operator != (const char * cpy);

	const bool operator != (const String & ref);

	String & operator = (const String & ref);

	String & operator = (const char * cpyChain);

	String & operator += (const String & ref);

	String & operator += (const char * cpyChain);

	void Trim();
private:
	//Crea una còpia que allocata
	void Alloc(unsigned int nSize)
	{
		size = nSize;
		chain = new char[size];
	}

};


#endif //_STRING_H_
