#ifndef _STRING_H_
#define _STRING_H_


#include <stdio.h>
#include <stdarg.h>
#include <assert.h>
#include <string.h>
#include "Queue.h"
class String{

	
	unsigned int len;
	unsigned int size; //memoria
public:
	char * chain;
	String();

	String(unsigned inta);

	String(const char * cpy, ...);

	String(const String & ref);


	~String();

	//Utils
	void Clear();
	unsigned int getLen() const ;
	unsigned int getSize() const;
	const char* getString() const;
	//Methods
	void prefix(String ref);

	void prefix(const char * ref);
	//Operators

	bool operator == (const String & ref);

	bool operator == (const char * cpy);

	bool operator != (const char * cpy);

	bool operator != (const String & ref);

	const String & operator = (const String & ref);

	const String & operator = (const char * cpyChain);

	const String & operator += (const String & ref);

	const String & operator += (const char * cpyChain);

	void Trim2();

	void Trim(bool, bool, char);

	void Reallocate(unsigned int newMem);

	void String::Cut(unsigned int Li, unsigned int Ri);

	void Substitute(const char * original, const char * result);
	//Little methods
	void Find(const char* , Queue<unsigned int>&);
	void PrepareString(const Queue<unsigned int>& ref);
private:
	//Crea una c�pia que allocata
	void Alloc(unsigned int nSize)
	{
		chain = new char[nSize];
		size = nSize;
		}		
};


#endif //_STRING_H_
