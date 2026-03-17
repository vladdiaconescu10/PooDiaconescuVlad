#include <iostream>
#include "Sort.h"
using namespace std;
int Sort::GetElementsCount()
{
	return this->nrElemente;
}
int  Sort::GetElementFromIndex(int index)
{
	return this->a[index];
}
void Sort::Sort(int nrElemente, int* array) {
	this->nrElemente = nrElemente;
	this->a = new int[nrElemente];
	for (int i = 0; i < nrElemente; i++) {
		this->a[i] = array[i];
	}
}void Sort::BubbleSort(bool ascendent)
{
	int i, j, *a = this->a, aux;
	int n = GetElementsCount();
	for (i=0; i<n; i++)
		for (j = i + 1; j < n - 1; j++) {
			if (ascendent == true){
			
				if (a[i] < a[j]) {
					aux = a[i];
					a[i] = a[j];
					a[j] = aux;
				}
			}
			else if (a[i] > a[j]) {
				aux = a[i];
				a[i] = a[j];
				a[j] = aux;
			}
		}
}


void Sort::InsertSort(bool ascendent)
{
	int count = GetElementsCount();
	for (int i = 1; i < count; i++) {
		int key = a[i];
		int j = i - 1;

		if (ascendent) {
			// Sortare Crescătoare
			while (j >= 0 && a[j] > key) {
				a[j + 1] = a[j];
				j--;
			}
		}
		else {
			// Sortare Descrescătoare
			while (j >= 0 && a[j] < key) {
				a[j + 1] = a[j];
				j--;
			}
		}
		a[j + 1] = key;
	}
}


void Sort::QuickSort(bool ascendent)
{
	int count = GetElementsCount();
	
	if (count > 0) {
		QuickSortHelper(0, count - 1, ascendent);
	}
}

void Sort::QuickSortHelper(int low, int high, bool ascendent)
{
	if (low < high) {
		int pi = Partition(low, high, ascendent);

		
		QuickSortHelper(low, pi - 1, ascendent);
		QuickSortHelper(pi + 1, high, ascendent);
	}
}

int Sort::Partition(int low, int high, bool ascendent)
{
	int pivot = a[high]; 
	int i = (low - 1); 
	int aux; 
	for (int j = low; j <= high - 1; j++) {
		
		bool condition = ascendent ? (a[j] < pivot) : (a[j] > pivot);

		if (condition) {
			i++;
			aux = a[i];
			a[i] = a[j];
			a[j] = aux;
			 
		}
	}
	aux = a[i + 1];
	a[i + 1] = a[high];
	a[high] = aux;
	return (i + 1);
}

void Sort::Print()
{
	int n = GetElementsCount();
	for (int i = 0; i < n; i++)
		cout << GetElementFromIndex(i) << " ";
}