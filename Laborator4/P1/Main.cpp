#include <iostream>
#include "Sort.h"

using namespace std;

int main() {
	int date1[] = { 45, 12, 78, 4, 99, 23, 8 };
	Sort lista1(7, date1);
	cout << "Initial: ";
	lista1.Print();

	cout << endl;

	lista1.QuickSort(true); 
	cout << "Dupa QuickSort (Crescator): ";
	lista1.Print();


	int date2[] = { 100, 50, 200, 10, 30, 80 };
	Sort lista2(6, date2);

	lista2.InsertSort(true); 
	cout << "Dupa InsertSort (Crescator): ";
	lista2.Print();

	int date3[] = { 100, 50, 200, 10, 30};
	Sort lista3(6, date2);

	cout << endl;

	lista3.QuickSort(true);
	cout << "Dupa QuickSort (Crescator): ";
	lista3.Print();
}