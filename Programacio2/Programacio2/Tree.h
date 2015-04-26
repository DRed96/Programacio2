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
	//TYPE2 = tree_node<TYPE>*;
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
			node->PostorderRECl(list);
			tmp = tmp->next;
			
		}
		list.Add(this);
		
	}
	/*
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
		node<tree_node<TYPE>*> * tmp = sons->start;
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
	*/
	
	
	/*
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
	}*/
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

	/*
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
	}*/

	/*void PostorderIT(List <tree_node<TYPE>*> * list)
	{
		Stack <tree_node<TYPE>*> sonStack;
		tree_node<TYPE>* it_node = root;
		node<tree_node<TYPE>*>* tmp;


		while (sonStack.isOver != true){

			tmp = it_node->sons.end;

			while (tmp != NULL)
			{
				sonStack.PushBack(tmp->data);
				tmp = tmp->prev;
			}

			//Perqu� no puc fer servir el Top??
			it_node = sonStack.data[sonStack.nElements- 1];

			if (it_node->sons.start == NULL){
				list->Add(it_node);
				sonStack.Pop();
			}

			if (it_node == it_node->father->sons.end->data)
			{
				//assert(1 != 1);
				sonStack.Pop(it_node);
				list->Add(it_node);
			}
		}
		//assert(1 != 1);
		//	assert(sonStack.isOver != true);
		list->Add(root);
	}*/


	void PostorderIT(List <tree_node<TYPE>*> * list)
	{
		Stack <tree_node<TYPE>*> sonStack;
		tree_node<TYPE>* it_node = root;
		node<tree_node<TYPE>*>* tmp;


		while (sonStack.isOver != true){

			tmp = it_node->sons.end;

			while (tmp != NULL)
			{
				sonStack.PushBack(tmp->data);
				tmp = tmp->prev;
			}

			//Perqu� no puc fer servir el Top??
			it_node = sonStack.data[sonStack.nElements - 1];

			if (it_node->sons.start == NULL){
				list->Add(it_node);
				sonStack.Pop();
			}

			if (it_node == it_node->father->sons.end->data)
			{
				//assert(1 != 1);
				sonStack.Pop(it_node);
				list->Add(it_node);
			}
		}
		//assert(1 != 1);
		//	assert(sonStack.isOver != true);
		list->Add(root);
	}



	void PretorderIT(List <tree_node<TYPE>*> * list) const
	{
		root->PreorderIT(list);
	}
	void InorderIT(List <tree_node<TYPE>*> * list) const
	{
		root->InorderIT(list);
	}
};
