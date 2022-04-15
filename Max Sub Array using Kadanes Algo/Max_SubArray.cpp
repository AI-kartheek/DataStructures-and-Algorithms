/*
Question:: Print the sum of Maximum sub-array from the array along with it's start and end positions?

Solution::
	Kadane's Algorithm gives O(n) time complexity for finding maximum sub-array problem.
	As Brute Force approach gives O(n^2) where as Divide and Conquer Approach gives nealy equal to
	Merge sort time complexity.

	Hence Kadane's Algorithm is efficient one for Maximum sub array.
*/

#include<iostream>
#include<climits>

using namespace std;

int main()
{
	int n;
	cout<< "Enter Number of Elements: ";
	cin>> n;
	int arr[n];
	cout<< "Enter "<< n << " Elements:\n";
	for(int i=0; i<n; i++)
		cin>> arr[i];

	// find maximum sub-array
	int max_sum = INT_MIN, current_sum=0, temp_idx=0, start=0, end=0;
	for(int i=0; i<n; i++){
		current_sum += arr[i];

		if(max_sum < current_sum){
			max_sum = current_sum;
			start = temp_idx;
			end = i;
		}

		if(current_sum < 0){
			current_sum = 0;
			temp_idx = i+1;
		}
	}

	// output results
	printf("Maximum Sub-Array sum = %d, Which is present at [%d, %d].", max_sum, start, end);

	return 0;
}