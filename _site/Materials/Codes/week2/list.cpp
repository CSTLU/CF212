#include <iostream>
using namespace std;

struct node
{
  int data;
  node *next;
};

int main(int argc, char const *argv[])
{
	node *head = NULL;
	// head -> 5
	node *new_element = new node;
	new_element->data = 5;
	new_element->next = NULL;

	head = new_element;
	//head->5->7
	node *new_pt2 = new node;
	new_pt2->data = 7;
	new_pt2->next = NULL;
	head -> next = new_pt2;

	//head->3->5->7
	node *new_pt3 = new node;
	new_pt3->data = 3;
	new_pt3->next = NULL;

	new_pt3->next = head;
	head = new_pt3;

	node *p = head;
    while (p != NULL)
    {
        // Process Node
        cout<<p->data<<" ";
        p = p->next;
    }
	return 0;
}