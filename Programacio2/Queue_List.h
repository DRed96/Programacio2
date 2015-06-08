#pragma once
#include "List.h"

template <class T>
class Queue_List
{
	
	List <T> data;
	node<T> * fake_start;
public:
	
	

	//Constructor
	Queue_List() 
	{}

	~Queue_List()
	{
		fake_start = NULL;
	}

	//Getters
	unsigned int getSize() const{return data.count();}
	//Methods
	unsigned int PushBack(const T & element)
	{
		
		unsigned int ret = data.Add(element);
		if (fake_start == NULL)
			fake_start = data.start;
		return ret;
	}




	bool PopFirst(T& ref)
	{
		if (fake_start != NULL)
		{
			ref = fake_start->data;
			fake_start = fake_start->next;
			return true;
		}
		else
			return false;
	}

	//Read/write operator
	 T& operator [](unsigned int index)
	 {
		 assert(index < data.count());
			return data[index];
		
	 }
};
