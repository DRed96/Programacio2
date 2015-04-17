#pragma once
#include "List.h"
#include "Stack.h"

/*
DEURES

Add(Amb punter a node pare)
<<<<<<< HEAD
=======
Recursiu
>>>>>>> origin/master

*/
template <class TYPE>
struct tree_node {
	TYPE data;
	tree_node * father;
	List <tree_node> * sons;


	tree_node(const TYPE a)
	{
		data = a;
		father = NULL;
	}
	// Si el Add el fem abans del for, es un preorder,
	// Si el fem despres, un post-order

	void VisitAll(List <TYPE> * list) //Postorder recursiu
	{
		node<TYPE> tmp = sons->start;
		for (tmp != NULL)
		{
			tmp = tmp->next;
			node->VisitAll(list);
		}
		list.Add(data);
	}

	void VisitAll2(List <TYPE> * list) //Preorder recursiu
	{
		list.Add(data);
		node<TYPE> tmp = sons->start;
		for (tmp != NULL)
		{
			tmp = tmp->next;
			node->VisitAll(list);
		}
	}

	void VisitAll4(List <TYPE> * list)  //Inorder iteratiu POSAR STACK
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

	void PreorderIT(List <TYPE> * list)
	{
		Stack <tree_node> sonList;
		list->node = root;
		while (node != NULL)
		{
			list->Add(node);

		}

	}
};
};

template <class TYPE>
class Tree
{
public:
	tree_node<TYPE>* root;
	unsigned int size;

	//Codi poc òptim al constructor
	Tree(const TYPE a)
	{
		root = new tree_node<TYPE>(a);
	}

	unsigned int Add(const TYPE& _data)
	{
		tree_node <TYPE> * newNode = new tree_node<TYPE>(_data);
		//ERROR!!
		//Quan intento accedir a sons no em deixa,
		//EN cas de no crear un nou node per root, tampoc puc accedir a father 
		root->sons->PushBack(newNode);

		newNode->father = root;
		size = 1;
		return size;
	}

	void VisitAllNodes(List <TYPE>* list) const
	{
		root->VisitAll(list);
	}
};
