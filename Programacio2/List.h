#ifndef _List_H_
#define _List_H_

#include <assert.h>
//#include "Swap.h"

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
	 //Constructor copia
	 List(const List <TYPE>& ref)
	 {
		 start = end = NULL;
		 size = 0;
		 node <TYPE> *tmp2 = ref.start;
		// for (unsigned int i = 0; i < ref.size; i++, tmp2 = tmp2->next)
		 while (tmp2)
		 {
			 Add(tmp2->data);
			 tmp2 = tmp2->next;
		 }
	 }

	//Destructor
	~List()
	{
		delAll();
	}

	unsigned int count() const
	{
		return size;
	}

	/**
	* Add new item at the end
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

	Add(const TYPE& input, unsigned int pos)
	{
		
		if (pos > size + 1)
		{

		}
		else
		{
			node<TYPE> newNode(input);
			if (start == NULL)
			{
				start = end = newNode;
			}

			if (pos == 0)
			{
				start->prev = newNode;
				newNode->next = start;
				start = newNode;

			}
			else
			{
				node<TYPE>*tmp = start;
				unsigned int counter = 0;
				while (counter < pos)
				{
					tmp = tmp->next;
					counter++;
				}
				node<TYPE>*tmp2 = tmp->next;

				tmp->next->prev = newNode;
				newNode->next = tmp->next;
				tmp
				
			}
				

			
		}
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


	void swapNodes(node<TYPE> * n1, node<TYPE>* n2)
	{
		node<TYPE>* tmp;
		//Prev

		if (n1 == start)
			start = n2;
		else if (n2 == start)
			start = n1;
		if (n1 == end)
			end = n2;
		else if (n2 == end)
			end = n1;

		if (n1->prev)
			n1->prev->next = n2;
		if (n2->prev)
			n2->prev->next = n1;

		//swap(n1->prev, n2->prev);
		tmp = n1->prev;
		n1->prev = n2->prev;
		n2->prev = tmp;

		//next
		if (n1->next)
			n1->next->prev = n2;

		if (n2->next)
			n2->next->prev = n1;

		//swap(n1->next, n2->next);
		tmp = n1->next;
		n1->next = n2->next;
		n2->next = tmp;
	}


	/**
	* read / write operator access directly to a position in the list
	*/
//Posar referencia
	TYPE& operator [](unsigned int index)
	{
		
		assert(index < size);
		
		node<TYPE>*  tmp = start;
		for (unsigned int i = 0; i < index; i++)
		{
		tmp = tmp->next;
		}
		return tmp->data;
		
	}

	const TYPE& operator [](unsigned int index)const
	{

		assert(index < size);

		node<TYPE>*  tmp = start;
		for (unsigned int i = 0; i < index; i++)
		{
			tmp = tmp->next;
		}
		return tmp->data;

	}
	//Concatenate two lists
	void operator += (const List<TYPE> & ref)
	{
		//assert(ref.start && ref.end);
		for (unsigned int i = 0; i < ref.size; i++)
		{
		Add(ref[i]);
		}
		/*
		List <TYPE> Copied_List(ref);
	
		end->next = Copied_List.start;
		Copied_List.start->prev = end;

		end = Copied_List.end;
		size += Copied_List.size;

		//Copied_List.start = NULL;
		Copied_List.end = NULL;*/
	}

	//Ordenar la llista fent bubble sort
	
	unsigned int BubbleSort()
	{
		bool change = true;
		unsigned int counter = 0;
		//for the optimization
		while (change == true)
		{
			change = false;
			node<TYPE>*  tmp = start;
			node<TYPE>*  tmp2 = tmp->next;
			while (tmp->next)
			{
				counter++;
				tmp2 = tmp->next;			
				if (tmp->data > tmp2->data)
				{
					TYPE swapTMP = tmp->data;
					tmp->data = tmp2->data;
					tmp2->data = swapTMP;
					change = true;
				}
				tmp = tmp2;
			}
		}
		return counter;
	}

	/**
	* returns the first apperance of data as index (-1 if not found)
	*/
	int find(const TYPE& data) const
	{
		node<TYPE>* tmp = start;
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


	unsigned int find_node_pos(const node<TYPE> & node) const
	{
		node<TYPE>* tmp = start;
		unsigned int index = 0;

		while (tmp != NULL)
		{
			if (tmp->data == node)
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

	bool Insert_List(unsigned int position, const List<TYPE>& ref)
	{
		if (position > size)
			return false;

		static List<TYPE> Copied_List(ref);
		node<TYPE> * tmp = start;
		
		if (position <= 0)
		{
			Copied_List.end->next = start;
			start->prev = Copied_List.end;

			start = Copied_List.start;
			
		}
		else
		{
			unsigned int i = 1;
			while (i < position)
			{
				tmp = tmp->next;
				i++;
				
			}

			node<TYPE> * tmp2 = tmp->next;

			if (tmp)
			{
				tmp->next = Copied_List.start;
				Copied_List.start->prev = tmp;
			}
			if (tmp2)
			{
				Copied_List.end->next = tmp2;
				tmp2->prev = Copied_List.end;
			}
			else
			{
				end = Copied_List.end;
			}
		}
		Copied_List.start = Copied_List.end = NULL;
		size += Copied_List.size;

		return true;
	}

};
#endif //_List_H_
