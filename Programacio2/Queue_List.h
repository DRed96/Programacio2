#pragma once
#include "List.h"

template <class T>
class Queue_List
{
	node<T> * fake_start;
	List <T> data;
public:
	

	//Constructor
	Queue_List() 
	{
		fake_start = data.start;
	}

	~Queue_List(){ }

	//Getters
	unsigned int getSize() const{return data.count();}

	//Methods
	unsigned int PushBack(const T & element)
	{
		return data.Add(element);
	}

	bool PopFirst(T& ref)
	{
		if (fake_start)
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
