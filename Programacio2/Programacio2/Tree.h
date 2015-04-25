#pragma once
#include "List.h"
#include "Stack.h"
#include "Queue.h"
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

	void PostorderREC(List <tree_node<TYPE>*>* list) //Postorder recursiu
	{
		node<TYPE> tmp = sons->start;
	
		for (tmp != NULL)
		{
			tmp = tmp->next;
			node->PostorderRECl(list);
		}
		list.Add(this);
		
	}

	void PreorderREC(List <tree_node<TYPE>*>* list) //Preorder recursiu
	{
		node<tree_node<TYPE>*> * tmp;
		tmp = sons.getStart();

		list->Add(this);
		while (tmp != NULL)
		{
			tmp->data->PreorderREC(list);
			tmp = tmp->next;
		}
		
	}

	
	void InorderREC(List <tree_node<TYPE>*>* list) //Preorder recursiu
	{
		const node<TYPE>* tmp;
		tmp = sons->start;
		unsigned int counter = 0;
		while (tmp)
		{
			if (counter >= size / 2)
			{
				list.Add(this);
			}
			tmp->InorderREC(list);
			counter++;
			tmp = tmp->next;
		}
		list->Add(this);
		
	}

	void InorderIT(List <tree_node<TYPE>*>* list)  //Inorder iteratiu POSAR STACK
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
		Stack <tree_node<TYPE>> sonStack;
		Stack <tree_node<TYPE>> secondStack;
		tree_node<TYPE> * it_node = root;
		node<TYPE>* tmp;
		
		while (it_node != NULL){
			/*if (it_node->sons != NULL)
				secondStack.PushBack(it_node);	
			
			if (it_node == it_node->father->sons->end){
				while (it_node != NULL)
				{
					it_node = secondStack.Pop();
					list->Add(it_node);
				}
			}*/

			tmp = it_node->sons->end;
			
			while (tmp != NULL)
			{
				sonStack.PushBack(tmp);
				tmp = tmp->prev;
			}

			it_node = sonStack.Top();
			
			//it_node = sonStack.Pop();

			if (it_node->sons == NULL){
				list->Add(it_node);
				sonStack.Pop;
			}

			if (it_node == it_node->father->sons->end)
			{
				it_node = sonStack.Pop();
				list->Add(it_node);
				it_node = sonStack.Top();
			}
		/*	if (it_node->father->sons->start = tmp->data)
				it_node = sonStack.Pop();
				list->Add(it_node);
				it_node = sonStack.Top();
				*/

		}
		list->Add(root);
	}
	

	void PreorderIT(List <tree_node<TYPE>*>* list)
	{

	Stack <tree_node<TYPE>*> sonStack;
	tree_node <TYPE> * badass = root; 
	node<TYPE>* tmp;
	//list->Add(root);
		while (badass != NULL)
		{
			list->Add(badass);
			//if (badass->sons)
				tmp = badass->sons->end;
			while (tmp != NULL)
			{
				sonStack.PushBack(tmp);
				tmp = tmp->prev;
			}	
			badass = sonStack.Pop(tmp);
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

	void PostorderREC(List <TYPE*>* list) const
	{
		root->PostorderREC(list);
	}

	void PreorderREC(List <tree_node<TYPE>*>* list) const
	{
		root->PreorderREC(list);
	}
	void InorderREC(List <tree_node<TYPE>*> * list) const
	{
		root->InorderREC(list);
	}

	void PostorderIT(List <tree_node<TYPE>*> * list) const
	{
		root->PostorderIT(list);
	}
	void PretorderIT(List <tree_node<TYPE>*> * list) const
	{
		root->PostorderIT(list);
	}
	void InorderIT(List <tree_node<TYPE>*> * list) const
	{
		root->PostorderIT(list);
	}
};
