#ifndef _QUEUE_ARRAY_H_
#define _QUEUE_ARRAY_H_
#include "DynArray.h"

template<class T>
class Queue_Array{
	unsigned int start_pos;
	DynArray<T> data;
public:

	Queue_Array() : start_pos(0)
	{}

	void Push(const T element)
	{
		
	}
	/*
	Constructors i destructors
	-Push
	PopFirst
	Peek?
	Operator []?
	*/



};


#endif /*_QUEUE_ARRAY_H_*/