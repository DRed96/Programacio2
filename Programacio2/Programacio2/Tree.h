#pragma once
#include "List.h"
#include "Stack.h"

/*
DEURES
Add(Amb punter a node pare)
Recursiu
*/

template <class TYPE>
struct tree_node {
	TYPE data;
	tree_node * father;
	List <tree_node<TYPE>*> sons;

	tree_node() : data(NULL), father(NULL)
	{}

	tree_node(const TYPE a) : data(a), father(NULL)
	{}

	~tree_node()
	{}
	// Si el Add el fem abans del for, es un preorder,
	// Si el fem despres, un post-order

	void PostorderREC(List <tree_node<TYPE>*> list) //Postorder recursiu
	{
		node<TYPE> tmp = sons->start;
		for (tmp != NULL)
		{
			tmp = tmp->next;
			node->VisitAll(list);
		}
		list.Add(data);
	}

	void PreorderREC(List <tree_node<TYPE>*> list) //Preorder recursiu
	{
		node<tree_node<TYPE>*> * tmp;
		tmp = sons.getStart()->data;


		while (tmp != NULL)
		{
			PreorderREC(list);
			tmp = tmp->next;
		}
		list.Add(data);
	}

	
	void InorderREC(List <TYPE*> list) //Preorder recursiu
	{
		node<TYPE>* tmp;
		tmp = sons->start;
		unsigned int counter = 0;
		while (tmp)
		{
			if (counter >= size / 2)
			{
				list.Add(data);
			}
			tmp->InorderREC(list);
			counter++;
			tmp = tmp->next;

		}
		
	}

	void InorderIT(List <TYPE> * list)  //Inorder iteratiu POSAR STACK
	{



		list.Add(data);
		unsigned int counter = 0;
		node<TYPE> tmp = sons->start;
		while (sons->size > counter)
		{
			Add(tmp->data);
			tmp = tmp->next;
			if (tmp->data->sons->start != NULL)
			{

			}

			sons->
				counter++;
		
		
		
		}
	}

	void PostorderIT(List <tree_node<TYPE>*> * list)
	{
		//Stack <tree_node<TYPE>> sonStack;
		Stack <tree_node<TYPE>*> sonStack;
		node<tree_node <TYPE> *> badass = sons->end;
		badass->data = root;
		while (badass != NULL)
		{
			list->Add(badass);
			while (tmp != NULL)
			{
				sonStack.PushBack(tmp);
				tmp = tmp->prev;
			}
			badass = sonStack.Pop(tmp);
		}
	}

	void PreorderIT(List <tree_node<TYPE>*> list)
	{
		Stack <tree_node> sonList;
		node <tree_node> badass = sons->start;
		badass = root;
		while (node != NULL)
		{
			
		}

	}
};


template <class TYPE>
class Tree
{
public:
	tree_node<TYPE>* root;
	unsigned int size;

	Tree() :root(NULL)
	{
	}

	tree_node<TYPE> * Add(const TYPE& _data, tree_node<TYPE> * newFather)
	{
		//assert(root != NULL && newFather == NULL);

		tree_node <TYPE> *newNode = new tree_node<TYPE>(_data);
		if (newFather == NULL && root == NULL)
		{
			root = newNode;
			newNode->father = NULL;
		}
		if (newFather != NULL && root != NULL)
		{
			newFather->sons.Add(newNode);
			newNode->father = newFather;
		} 
		size++;
		return newNode;
	}

	void PostorderREC(List <TYPE*> list) const
	{
		root->PostorderREC(list);
	}

	void PreorderREC(List <tree_node<TYPE>*> list) const
	{
		root->PreorderREC(list);
	}
	void InorderREC(List <TYPE> * list) const
	{
		root->InorderREC(list);
	}

	void PostorderIT(List <tree_node<TYPE>*> * list) const
	{
		root->PostorderIT(list);
	}
};
