#ifndef NODE
#define NODE
#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
	T value;
	Node * next;
public:
	Node(T value)
	{
		this -> value = value;
		this -> next = NULL;
	}
	~Node()
	{

	}
	
};
#endif