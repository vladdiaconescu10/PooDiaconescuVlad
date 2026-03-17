	#pragma once
#include <iostream>

class Sort
{
    int nrElemente = 10;
    int* a;

    int Partition(int low, int high, bool ascendent);
    void QuickSortHelper(int low, int high, bool ascendent);
public:
    void Sort::Sort(int nrElemente, int* array);
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};
