#include <iostream>
#include "NumberList.h"
using namespace std;
NumberList myList;
int main()
{		

	int count;
	myList.Init();
	
	myList.Add(1);
	myList.Add(2);
	myList.Add(3);
	myList.Add(6);
	myList.Add(5);
	myList.Add(4);
	myList.Add(9);
	myList.Add(8);
	
	myList.Sort();
	myList.Print();
}