#include <iostream>
using namespace std;
#include "LinkedList.h"
int main(int argc, char const *argv[])
{
	LinkedList<int> a;
	a.pushBack(5);
	a.pushBack(6);
	a.pushBack(7);
	a.pushBack(8);
	a.printAll();
	a.popBack();
	a.popBack();
	a.printAll();
	a.popBack();
	a.popBack();
	a.printAll();
	return 0;
}