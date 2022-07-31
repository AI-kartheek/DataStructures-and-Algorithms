/* C++ program for implementation of Heap Sort
    -> Time complexity of heapify sort is O(n).
*/
#include <iostream>

using namespace std;

// max heapify method.
void heapify(int arr[], int n, int i)
{
	int largest = i; // Initialize largest as root
	int l = 2 * i + 1; // find its left child.
	int r = 2 * i + 2; // find its right child.

	// If left child is larger than root
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest so far
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// If largest is not root
	if (largest != i) {
		swap(arr[i], arr[largest]);

		// Recursively heapify the affected sub-tree
		heapify(arr, n, largest);
	}
}

void heapSort(int arr[], int n)
{
	// Loop from end position of non-leaf nodes.
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// Delete all the elements from the maxheap to make ascending sort.
	for (int i = n - 1; i > 0; i--) {
		// Move current root to end
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

// main method starts
int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int n = sizeof(arr) / sizeof(arr[0]);

	heapSort(arr, n);

	cout << "Sorted array is :\n";
	printArray(arr, n);
}
