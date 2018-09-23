#ifndef LINKEDLIST
#define LINKEDLIST
#include <iostream>
using namespace std;
#include "Node.h"
template <typename T>
class LinkedList
{
	Node<T> *head;
	Node<T> * tail;
	int size;
public:
	LinkedList(){}
	//front
	void pushFront(T data)
	{
		Node<T> * newnode = new Node<T>(data);
		if (isEmpty())
		{
			this -> head = newnode;
			this -> tail = newnode;
		}
		else
		{
			newnode -> next = head;
			this -> head = newnode;
		}
		this -> size++;
	}

	bool popFront()
	{
		if (isEmpty())
		{
			return false;
		}else
		{
			if (this -> head == this -> tail)
			{
				delete this -> head;
				this -> head = NULL;
				this -> tail = NULL;
			}
			else
			{
				Node<T> *temp = head;
				head =  head -> next;
				delete temp;
			}
			this -> size--;
			return true;
		}
	}

	T topFront() const
	{
		return this -> head -> value;
	}

	//back
	void pushBack(T data)
	{
		Node<T> * newnode = new Node<T>(data);
		if (isEmpty())
		{
			this -> head = newnode;
			this -> tail = newnode;
		}
		else
		{
			this -> tail -> next = newnode;
			this -> tail = newnode;
		}
		this -> size++;
	}
	T topBack() const
	{
		return this -> tail -> value;
	}

	bool popBack()
	{
		if (isEmpty())
		{
			return false;
		}
		else
		{
			if (this -> head == this -> tail)
			{
				delete this -> head;
				this -> head = NULL;
				this -> tail = NULL;
			}
			else
			{
				Node<T> *temp = this -> head;
				while(temp-> next -> next != NULL)
				{
					temp = temp -> next;
				}
				this -> tail = temp;
				delete temp->next;
				temp->next = NULL;
			}
			this -> size --;
			return true;
		}
		
	}


	int Size()const
	{
		return this -> size;
	}

	bool isEmpty()const
	{
		return this -> head == NULL;
	}
	void printAll()const
	{
		Node<T> * temp = head;
		while(temp)
		{	
			cout<<temp -> value<<" ";
			temp = temp -> next;
		}
		cout<<endl;
	}
	~LinkedList(){}
	
};
#endif