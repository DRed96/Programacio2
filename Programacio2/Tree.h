#pragma once

#include "List.h"
#include "Stack.h"
#include "Queue.h"

template <class TYPE>
struct tree_node
{
	TYPE data;
	tree_node * father;
	List <tree_node<TYPE>*> sons;
	//TYPE2 = tree_node<TYPE>*;
	tree_node() : data(NULL), father(NULL)
	{
		sons.start = sons.end = NULL;
	}

	tree_node(const TYPE a) : data(a), father(NULL)
	{
		sons.start = sons.end = NULL;
	}

	~tree_node()
	{}

	void Clear(tree_node<TYPE> * starterNode)
	{
		node<tree_node<TYPE>*> * tmp = starterNode->sons.start;
		while (tmp)
		{
			Clear(tmp->data);
			tmp = tmp->next;
			starterNode->sons.size--;
		}
		delete tmp;
	}


	//--------------------------------
	// Recursive search functions
	//--------------------------------


	void PreOrderREC(List <tree_node<TYPE>*>* list)
	{
		node<tree_node<TYPE>*> * tmp;
		tmp = sons.getStart();

		list->Add(this);
		while (tmp != NULL)
		{
			tmp->data->PreOrderREC(list);
			tmp = tmp->next;
		}

	}

	void PostOrderREC(List <tree_node<TYPE>*>* list)
	{
		node<tree_node<TYPE>*> * tmp = sons.start;
		while (tmp != NULL)
		{
			tmp->data->PostOrderREC(list);
			tmp = tmp->next;

		}
		list->Add(this);

	}

	void InOrderREC(List <tree_node<TYPE>*>* list)
	{
		const node<tree_node<TYPE>*>* tmp;
		tmp = sons.start;
		unsigned int counter = 0;

		do
		{
			if (counter < sons.size / 2)
			{
				tmp->data->InOrderREC(list);
				counter++;
				tmp = tmp->next;
			}

			list->Add(this);
			if (tmp)
			{
				tmp->data->InOrderREC(list);
				tmp = tmp->next;
			}


		} while (tmp);
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


	//--------------------------------
	// Add & Clear
	//--------------------------------

	tree_node<TYPE> * Add(const TYPE& _data, tree_node<TYPE> * newFather = NULL)
	{
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

	//This function is recursive, similar to Preorder REC
	void Clear(tree_node<TYPE> * starterNode = NULL)
	{

		if (starterNode == NULL)
			starterNode = root;

		//This if is to avoid memory access violations
		if (starterNode != root)
			starterNode->father->sons.size--;

		root->Clear(starterNode);
	}


	//--------------------------------
	// Recursive search functions
	//--------------------------------
	void PostOrderREC(List <tree_node<TYPE>*>* list)
	{
		root->PostOrderREC(list);
	}

	void PreOrderREC(List <tree_node<TYPE>*>* list)
	{
		root->PreOrderREC(list);
	}
	void InOrderREC(List <tree_node<TYPE>*> * list)
	{
		root->InOrderREC(list);
	}

	//--------------------------------
	// Iterative search functions
	//--------------------------------

	void PreOrderIT(List <tree_node<TYPE>*>* list) const
	{
		Stack <tree_node<TYPE>*> son_stack;
		tree_node <TYPE> * it_node = root;
		node<tree_node<TYPE>*>* tmp;
		bool checker = true;
		while (checker &&it_node != NULL)
		{
			list->Add(it_node);

			tmp = it_node->sons.end;
			while (tmp != NULL)
			{
				son_stack.PushBack(tmp->data);
				tmp = tmp->prev;
			}
			checker = son_stack.Pop(it_node);
		}
	}

	void PostOrderIT(List <tree_node<TYPE>*> * list) const
	{
		Stack <tree_node<TYPE>*> sonStack;
		tree_node<TYPE>* it_node = root;
		node<tree_node<TYPE>*>* tmp;
		bool checker = true;
		//Checker checks if the Pops of the stack work correctly

		while (checker == true && it_node != NULL)
		{
			tmp = it_node->sons.end;

			if (tmp){
				while (tmp->prev != NULL)
				{
					sonStack.PushBack(tmp->data);
					tmp = tmp->prev;
				}
				sonStack.PushBack(tmp->data);
			}

			checker = sonStack.Pop(it_node);

			if (it_node->sons.count() == 0){
				list->Add(it_node);
			}

			/*
			This if(and while) gets triggered when the last item on the list it's the same
			as the las son of the father of the iterative node, the purpose of this is that
			the function only goes to the node father when it has finished with all the sons
			*/
			if (list->count() != 0 && list->end->data == it_node->father->sons.end->data){
				while (list->end->data == it_node->father->sons.end->data)
				{
					if (it_node->father)
						it_node = it_node->father;
					list->Add(it_node);
					if (it_node == root)
					{
						it_node = NULL;
						break;
					}
				}
				checker = sonStack.Pop(it_node);
			}
		}
	}

	//I have not been able to complete this method
	void InOrderIT(List <tree_node<TYPE>*> * list) const
	{
		tree_node<TYPE>* it_node = root;
		node<tree_node<TYPE>*>* tmp;
		Stack <tree_node<TYPE>*> sonStack;
		tree_node<TYPE>* debugStack;

		float counter;

		while (it_node){
			counter = 0.0;
			tmp = it_node->sons.end;
			sonStack.Top(debugStack);
			if (tmp == NULL)
			{

				list->Add(it_node);
				sonStack.Top(debugStack);  //Borrar
				if (it_node->father == debugStack || root == debugStack)
				{
					sonStack.Pop(it_node);
					list->Add(it_node);
				}

			}
			else{
				if (it_node->sons.count() != 1)
				{
					while (tmp != NULL && counter < (float)it_node->sons.count() / 2)
					{
						sonStack.PushBack(tmp->data);
						sonStack.Top(debugStack);
						tmp = tmp->prev;
						++counter;
					}

					sonStack.PushBack(it_node);

					sonStack.Top(debugStack);

					while (tmp != NULL)
					{
						sonStack.PushBack(tmp->data);

						sonStack.Top(debugStack);

						tmp = tmp->prev;
					}
					if (debugStack == it_node)
					{
						sonStack.Pop();
					}
				}
				else
				{
					sonStack.PushBack(it_node);
					sonStack.PushBack(tmp->data);
				}
			}
			sonStack.Pop(it_node);
		}
	}
	
	void Transversal_Order_IT(List<tree_node<TYPE>*>& ref) const
	{
		Queue<tree_node<TYPE> *> Sons;
		//This tree_node will be the one we add to ref
		tree_node<TYPE> * it_node = root;
		//And this,the one that travels trough the sons
		node<tree_node<TYPE>*>* tmp;
		do
		{
				ref.Add(it_node);
				//Adds all Sons
				tmp = it_node->sons.start;

				while (tmp)					
				{
					Sons.PushBack(tmp->data);
					tmp = tmp->next;
				}
		} while (Sons.PopFirst(it_node));
	}
};

/*
tmp = it_node->sons.end;
if (!tmp)
list->Add(it_node);
else
{
for (; counter <= (float)it_node->sons.count() / 2; counter++, tmp = tmp->prev)
{
sonStack.PushBack(tmp->data);
}

sonStack.PushBack(it_node);

for (; tmp; tmp = tmp->prev)
{
sonStack.PushBack(tmp->data);
}

if (debugStack == )
}




}*/