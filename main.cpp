#include "TestFunctions.h"
#include<iostream>
#include <chrono>
using namespace std;

int main()
{
	srand(time(NULL));
	int size = 30;
	int* arr1;
	create_array(arr1, size);
	cout << sorting_test(&insertion_sort, arr1, size);
	
	
	/*int size = 30;

	cout << "\n\nInsertion Sort:\n";

	int* arr1;

	create_array(arr1, size);
	//display(arr1, size);

	create_random(arr1, size);
	display(arr1, size);

	insertion_sort(arr1, size);
	display(arr1, size);


	cout << "\n\nSelection Sort:\n";

	int* arr2;

	create_array(arr2, size);
	//display(arr2, size);

	create_random(arr2, size);
	display(arr2, size);

	insertion_sort(arr2, size);
	display(arr2, size);


	cout << "\n\nMerge Sort:\n";

	int* arr3;

	create_array(arr3, size);
	//display(arr3, size);

	create_random(arr3, size);
	display(arr3, size);

	insertion_sort(arr3, size);
	display(arr3, size);*/






	//prevent program closing
		int z;
		cout << "\n\nEnter any character key, then press enter: ";
		cin >> z;
}