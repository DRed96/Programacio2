#pragma once
#include "List.h"

template <class T>
class Queue_List
{
public:
	List <T> data;

	//Constructor
	Queue_List()
	{}

	~Queue_List(){ }

	//Methods
	void PushBack(const T& newValue)
	{
		data.Add(newValue);
	}

	bool PopFirst(T& ref)
	{
		
		ref = data.start->data;
		if (data.del(data.start) == false)
		{
			ref = NULL;
			return false;
		}
	}

	void PopFirst(){
		return (data.del(data.start));
	}

	unsigned int Count()
	{
		return data.count();
	}

	//Read/write operator
	 T& operator [](unsigned int index)
	 {
		 assert(index < data.count());
			return data[index];
		
	 }
};
