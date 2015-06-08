#ifndef __p2Qeue_H__
#define __p2Qeue_H__

//#include "p2Assert.h"

/**
* Contains items from double linked list
*/
template<class tdata>
struct p2Qeue_item
{
	tdata                 data;
	p2Qeue_item<tdata>*   next;

	inline p2Qeue_item(const tdata& _data) : data(_data), next(NULL)
	{}
};

/**
* Manages a double linked list
*/
template<class tdata>
class p2Qeue
{

public:

	p2Qeue_item<tdata>*   start;

public:

	/**
	* Constructor
	*/
	inline p2Qeue() : start(NULL)
	{}

	/**
	* Destructor
	*/
	~p2Qeue()
	{
		Clear();
	}

	/**
	* Get Size
	*/
	unsigned int Count() const
	{
		unsigned int result = 0;
		p2Qeue_item<tdata>* tmp;

		for (tmp = start; tmp != NULL; tmp = tmp->next)
			++result;

		return result;
	}

	/**
	* Get last item
	*/
	p2Qeue_item<tdata>* GetLast()
	{
		p2Qeue_item<tdata>* tmp = start;

		while (tmp != NULL && tmp->next != NULL)
			tmp = tmp->next;

		return tmp;
	}

	/**
	* push new item
	*/
	void Push(const tdata& item)
	{
		p2Qeue_item<tdata>*   p_data_item;
		p_data_item = new p2Qeue_item < tdata >(item);

		p2Qeue_item<tdata>* last = GetLast();

		if (last == NULL)
		{
			start = p_data_item;
		}
		else
		{
			last->next = p_data_item;
		}
	}

	/**
	* Deletes an item from the list
	*/
	bool Pop(tdata& item)
	{
		
		bool result = false;

		
		p2Qeue_item<tdata>* last = GetLast();

		if (last != NULL)
		{
			p2Qeue_item<tdata>* tmp = start;

			if (tmp == NULL)
				return result;

			while (tmp->next != last)
				tmp = tmp->next;

			item = tmp->next->data;
			{
				delete tmp->next;
				tmp->next = NULL;
			}
			result = true;
		}

		return result;
	}

	/**
	* Reads one of the values
	*/
	const tdata* Peek(unsigned int index) const
	{
		unsigned int i = 0;
		p2Qeue_item<tdata>* tmp;

		for (tmp = start; tmp != NULL && i < index; tmp = tmp->next)
			++i;

		if (tmp != NULL)
			return &(tmp->data);

		return NULL;
	}

	/**
	* Destroy and free all mem
	*/
	void Clear()
	{
		p2Qeue_item<tdata>*   p_data;
		p2Qeue_item<tdata>*   p_next;
		p_data = start;

		while (p_data != NULL)
		{
			p_next = p_data->next;
			if (p_data != NULL)
			{
				delete p_data;
				p_data = NULL;
			}
			p_data = p_next;
		}

		start = NULL;
	}

	tdata & operator [](unsigned int index)
	{
		p2Qeue_item<tdata>* tmp;
		unsigned int i = 0;
		for ( tmp = start; tmp != NULL && i < index; tmp = tmp->next)
			++i;
	
		return tmp->data;
	}

};
#endif /*__p2Qeue_H__*/