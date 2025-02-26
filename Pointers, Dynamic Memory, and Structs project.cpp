// Pointers, Dynamic Memory, and Structs project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int* ReverseArray(int const arr[], int size);
void print(int const arr[], int size, int* p);

int main()
{
	int size = 10;
	
	int const arr[10] = { 1,2,3,4,5,6,7,8,9,10};
 
	int* p = ReverseArray(arr, size);
    print(arr, size, p);
}

int* ReverseArray(int const arr[], int size)
{
	int reverseAR[10];
	const int* ptr = arr;
	int *ptr2 = reverseAR;
	for (size=0; size < 10; size++)
	{
			reverseAR[size] == *ptr + size - 1;
	}
	return  ptr2;
}

void print(int const arr[], int size, int* p)
{
	
	cout << "original array:" << " ";
	for (size = 0; size < 10; size++)
	{
		cout <<  arr[size] << " ";
	}
	cout << endl;
	cout << "reversed array:" << " ";
	for (int I=9; I>= 0; I--)
	{
		cout << *p+I << " ";
	}
	cout << endl;
}
