#include "TestFunctions.h"
#include <chrono>


//DEBUG FUNCTIONS

	void display(int* array_ptr, int size)
{
	cout << "Displaying Array: ";
	for (int i = 0; i < size; i++)
	{
		cout << array_ptr[i] << " ";
	}
	cout << endl;
}



//ARRAY CREATION FUNCTIONS

	void create_array(int* &array_, int size)
	{
		array_ = new int[size];
	}

	void create_random(int* &array_, int size)
	{
		delete array_;
		array_ = new int[size];

		for (int i = 0; i < size; i++)
		{
			array_[i] = rand() % 1000;
		}
	}

	void create_ascending(int* &array_, int size)
	{
		delete array_;
		array_ = new int[size];

		for (int i = 0; i < size; i++)
		{
			array_[i] = i;
		}
	}

	void create_descending(int* &array_, int size)
	{
		delete array_;
		array_ = new int[size];

		for (int i = 0; i < size; i++)
		{
			array_[i] = size - i - 1;
		}
	}



//SORTING FUNCTIONS

	void selection_sort(int* &array_, int size)
	{
		int smallest = 0; //will point to smallest of unsorted list
		int holder; //holds values during swithing so we don't lose data

		for (int i = 0; i < size; i++)
		{
			smallest = i; //smallest set to default beginning of unsorted

			//scour unsorted for smallest position
				for (int j = i; j < size; j++)
				{
					if (array_[j] < array_[smallest])
					{
						smallest = j;
					}
				}

			//switch position i with smallest
				holder = array_[i];
				array_[i] = array_[smallest];
				array_[smallest] = holder;
		}
	}

	void insertion_sort(int* &array_, int size)
	{
		int holder;

		//iterate through each item
		for (int i = 0; i < size; i++)
		{
			//while item is smaller than one before, swap
			while (array_[i] < array_[i - 1])
			{
				holder = array_[i - 1];
				array_[i - 1] = array_[i];
				array_[i] = holder;
				i--;
			}	
		}
	}

	void merge_sort(int* &array_, int from, int to)
	{
			int beginning = from; //beginning of list
			int middle = ((to - from) / 2) + 1 + from; //middle of list
			int size = to - from + 1;

		//if size greater than 2, split (RECURSION)
			if (size > 2)
			{
				merge_sort(array_, from, (middle - 1));
				merge_sort(array_, middle, to);
			}

		//compare beginning and middle; swap
			//holder array; sorted values placed here first, then copied to original
				int* holder_array = new int[size];

			//iterators which will choose which 2 to compare
				int iteraror1 = beginning;
				int iterator2 = middle;

			//iterator which will go from 'from' to 'to'
				int iterator_array = from;
			
				while ((iteraror1 < middle) and (iterator2 < to + 1))
				{ //^this one line is the KEY TO THE WHOLE FUNCTION
					if (array_[iteraror1] < array_[iterator2])
					{
						holder_array[iterator_array] = array_[iteraror1];
						iteraror1++;
						iterator_array++;
					}
					else
					{
						holder_array[iterator_array] = array_[iterator2];
						iterator2++;
						iterator_array++;
					}
				}

			//copy holder_array onto actual array_
				for (int i = from; i <= to; i++)
				{
					array_[i] = holder_array[i];
				}
				delete holder_array;
	}



//TESTING FUNCTIONS

	double sorting_test(void(*sorting_function)(int* &array_, int size), int* array_, int size)
	{
		auto start_time = high_resolution_clock().now();
		sorting_function(array_, size);
		auto end_time = high_resolution_clock().now();
		double result = end_time - start_time;
		return result;
	}