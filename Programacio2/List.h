#ifndef _List_H_
#define _List_H_

#include "Globals.h"

template<class TYPE>
struct node
{
	TYPE            data;
	node<TYPE>*		next;
	node <TYPE>*   prev;

	node(const TYPE& _data)
	{
		data = _data;
		next = prev = NULL;
	} 

};

//Manages a double linked list

template<class TYPE>
class List
{
public:
	node<TYPE>* start;
	node<TYPE>* end;
	
	unsigned int  size;
	//Constructor
	
	 List()
	{
		start = end = NULL;
		size = 0;
	}

	//Destructor
	~List()
	{
		delAll();
	}

	unsigned int count()
	{
		return size;
	}

	/**
	* Add new item
	*/
	unsigned int Add(const TYPE& input)
	{
		node<TYPE>*   newNode;
		newNode = new node < TYPE >(input);

		if (start == NULL)
		{
			start = end =newNode;
		}
		else
		{
			newNode->prev = end;
			end->next = newNode;
			end = newNode;
		}
		
		return ++size;
	}

	bool del(node <TYPE> * ndelete)
	{
		if (ndelete == NULL)
		{
			return false;
		}

		//Check if it's the first node
		if (ndelete->prev == NULL)
		{
			if (ndelete->next != NULL)
			{
				start = ndelete->next;
				start->prev = NULL;
				
			}
			else
			{
				end =  start = NULL;
			}
			
		}
		else
		{
			if (ndelete->next != NULL)
			{
				ndelete->next->prev = ndelete->prev;
				ndelete->prev->next = ndelete->next;
			}
			else
			{
				end = ndelete->prev;
				ndelete->prev->next = NULL;
			}

		}

		delete ndelete;
		size--;
		return true;
	}

	void delAll()
	{
		node<TYPE>*   tmp;
		node<TYPE>*   tmp2;
		tmp = start;

		while (tmp != NULL)
		{
			tmp2 = tmp->next;
			delete tmp;
			tmp = tmp2;
		}
		size = 0;
		start = end = NULL;

	}

	/**
	* read / write operator access directly to a position in the list
	*/
	TYPE& operator  [](const unsigned int index)
	{
		int pos = 0;
		node<TYPE>* sNode = start;
		
		while(sNode != NULL)
		{
			if (pos == index)
			{
				break;
			}

			++pos;
			sNode = sNode->next;
		}

		

		return(sNode->data);
	}

	/**
	* returns the first apperance of data as index (-1 if not found)
	*/
	int find(const TYPE& data)
	{
		node<TYPE>* tmp = fstart;
		int index = 0;

		while (tmp != NULL)
		{
			if (tmp->data == data)
				return(index);

			++index;
			tmp = tmp->next;
		}
		return (-1);
	}


	node <TYPE>*getStart() const
	{
		return start;
	}
	node <TYPE>*getEnd() const
	{
		return end;
	}
};
#endif //_List_H_
