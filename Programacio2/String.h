#ifndef _STRING_H_
#define _STRING_H_

#include <string.h>
class String{

	char * chain;
	unsigned int len;
	unsigned int size; //memoria
public:

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

	void Substitute(const char * original, const char * result);
	unsigned int Find(const char * original);
private:
	//Crea una c�pia que allocata
	void Alloc(unsigned int nSize)
	{
		size = nSize;
		chain = new char[size];
	}

};


#endif //_STRING_H_
