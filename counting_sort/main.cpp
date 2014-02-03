#include <iostream>
using std::cout;
using std::endl;

#include <ctime>
#include <cstdlib>

void countingSort(int [], int [], int, int); // function prototype

int main()
{
	// variable declarations
	int range = 11;
	const int SIZE = 10;
	int a[SIZE]; // array to be sorted
	int b[SIZE]; // output of sorted array

	// array initialization
	srand(time(NULL));
	for(int i = 0; i < SIZE; i++) {
		a[i] = rand() % range;
		cout << a[i] << " ";
	}
	cout << '\n' << endl;

	// call counting sort on array a;
	countingSort(a, b, SIZE, range);

	// display the sorted array
	for(int i = 0; i < SIZE; i++)
		cout << b[i] << " ";
	cout << endl;

	return 0;
}

void countingSort(int a[], int b[], int n, int k)
{
	// create a new array and initialize it to 0
	int *c = new int[k]; // temporary array for the values in array a
	for(int i = 0; i < k; i++)
		c[i] = 0;

	// loop through array a and increment the number of times a value appears
	for(int j = 0; j < n; j++)
		c[a[j]] = c[a[j]] + 1;

	// loop through array c and calculate the numbers of elements less than or equal to i
	for(int i = 1; i < k; i++)
		c[i] = c[i] + c[i-1];

	// loop through array a and insert the value in its correct position in array b
	for(int j = n-1; j >= 0; j--) {
		b[c[a[j]]-1] = a[j];
		c[a[j]] = c[a[j]] - 1;
	}

	delete [] c;
}