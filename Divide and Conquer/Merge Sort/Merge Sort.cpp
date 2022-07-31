#include<iostream>
using namespace std;

void MergeSort(int *, int, int);
void Merge(int *, int, int, int);

int main(){
	cout<< "Enter size of array: ";
	int n;
	cin>> n;
	int arr[n];
	cout<< "Enter "<< n << " Elements:\n";
	for(int i=0; i<n;i++)
		cin>> arr[i];

	// Merge Sort
	MergeSort(arr, 0, n-1);

	// display sorted results
	cout<< "sorted Elements are:: ";
	for(int i=0; i<n; i++){
		cout<< arr[i]<< " ";
	}
}

void MergeSort(int *A, int start, int end){
	if(start < end){
		int mid = (end - start)/2 + start;  // which reduces stack overflow for int and is equal to (end+start)/2
		MergeSort(A, start, mid);
		MergeSort(A, mid+1, end);
		Merge(A, start, mid, end);
	}
}

void Merge(int *A, int start, int mid, int end){
	// New Array B which stores the sorted values.
	int B[end-start+1], i=start, j=mid+1, k=0;

	while(i<= mid && j<= end){
		if(A[i] < A[j]){
			B[k] = A[i];
			i++;
		}
		else{
			B[k] = A[j];
			j++;
		}
		k++;
	}

	while(i <= mid){
		B[k] = A[i];
		i++;
		k++;
	}

	while(j <= end){
		B[k] = A[j];
		j++;
		k++;
	}

	// replacing sorted values from B to A
	for(int i=start; i<=end; i++){
		A[i] = B[i-start];
	}
}