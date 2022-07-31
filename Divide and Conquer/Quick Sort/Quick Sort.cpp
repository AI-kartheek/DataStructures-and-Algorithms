#include<iostream>

using namespace std;

// O(n) time complexity..
int partetion(int arr[], int start, int end)
{
    int pivot = arr[start], temp = start;
    
    while (start < end)
    {
        while (arr[++start] < pivot);
        while (arr[end--] >= pivot);
        if(start < ++end) swap(arr[start], arr[end]);
    }
    swap(arr[end], arr[temp]);
    return end;
}

void printArray(int arr[], int n)
{
    for(int i=0; i<n; i++) cout<< arr[i] << " ";
    cout<< endl;
}

void quickSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int mid = partetion(arr, start, end);
        quickSort(arr, start, mid-1);
        quickSort(arr, mid+1, end);
    }
}

int main()
{
    int arr[] = {4,3,8,3,9,4,1,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n-1);
    printArray(arr, n);
}