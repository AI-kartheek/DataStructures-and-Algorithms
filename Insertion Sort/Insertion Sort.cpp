#include<iostream>
using namespace std;

int main(){
	cout<< "Enter size of array: ";
	int n;
	cin>> n;
	int arr[n];
	cout<< "Enter "<< n << " Elements:\n";
	for(int i=0; i<n;i++)
		cin>> arr[i];

	// Insertion sort
	for(int i=1; i<n; i++){
		int temp = arr[i];
		int j = i-1;
		while(j>=0 && arr[j] > temp){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = temp;
	}

	// display sorted results
	cout<< "sorted Elements are:: ";
	for(int i=0; i<n; i++){
		cout<< arr[i]<< ends;
	}
}