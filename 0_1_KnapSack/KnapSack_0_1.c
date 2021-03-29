
#include<stdio.h>
#include<stdlib.h>
typedef struct Bucket{
	int index;
	int Wt;
	int Val;
}Bucket;

void QuickSort(Bucket *, int , int );
int Partetion(Bucket *, int , int );
int max(int a, int b) { return (a > b)? a : b; }
 
 Bucket* knapSack(int W, Bucket *B, Bucket temp[], int n)
 {
   int i,j;
   int K[n+1][W+1];
   QuickSort(B, 0, n-1);
   
   for (i = 0; i <= n; i++)
   {
       for (j = 0; j <= W; j++)
       {
           if (i==0 || j==0)
               K[i][j] = 0;
           else if (B[i-1].Wt <= j)
                  K[i][j] = max(B[i-1].Val + K[i-1][j- B[i-1].Wt],  K[i-1][j]);
           else
                  K[i][j] = K[i-1][j];
       }
   }
   
   int x, Max_profit;
   Max_profit = K[n][W];
   printf("\nMaximum Profit obtained = %d\n", Max_profit);
   int Max_weight = W;
   
   for(i=n-1; i>=0; i--){ // we start form  last before row 
    x = 0;
   	for(j=0; j<=W; j++){
   		if(K[i][j] == Max_profit){
   			temp[B[i].index].index = 0;
   			x=1;
   			break;
		   }
	
	   }
	if(x == 0){
		Max_weight -= B[i].Wt;
		Max_profit = K[i][Max_weight];
		temp[B[i].index].index = 1;
	}
   }
   
   return temp;
 }
 
int main()
{
    int i,j;
    int n;  //number of items
    int M;  //capacity of knapsack
 
    printf("Enter the no. of items: ");
    scanf("%d", &n);
 	Bucket *B, temp[n];
 	B = (Bucket*) malloc(n*sizeof(Bucket));
    
    printf("Enter the weight and price of all items:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d%d", &B[i].Wt, &B[i].Val);
        B[i].index = i;
        temp[i] = B[i];
    }
 
    printf("enter the capacity of knapsack : ");
    scanf("%d", &M);
 	
 	
 
    Bucket *result = knapSack(M, B, temp, n);
    printf("\nResults of 0/1 KnapSack are::\n");
	for(i=0;i<n;i++){
		if(result[i].index == 1)
			printf("For Weight: %d and Profit: %d ----> %d (Selected)\n", result[i].Wt, result[i].Val, result[i].index);
		else
			printf("For Weight: %d and Profit: %d ----> %d (Not-Selected)\n", result[i].Wt, result[i].Val, result[i].index);
	}
 
    return 0;
}

// Quick Sort function...
void QuickSort(Bucket *ptr, int start, int end)
{
int p;
if(start >= end)
  return;

p = Partetion(ptr, start, end);
QuickSort(ptr, start, p-1);
QuickSort(ptr, p+1, end);

}

//Partetion  function in Quick Sort...
int Partetion(Bucket *ptr, int start, int end)
{
  int pivot, p, i;
  Bucket temp;
  pivot = ptr[end].Wt;
  p = start;
  
  for(i=start;i<end;i++)
  {
    if(ptr[i].Wt <= pivot)
     {
         temp = ptr[i];
         ptr[i] = ptr[p];
         ptr[p] = temp;
         p++;
      }
   }
   
   temp = ptr[p];
   ptr[p] = ptr[end];
   ptr[end] = temp;
   
   return p;
}
