#include <stdio.h>
#include <stdlib.h>

typedef struct EncodedData{
    char ch;
    char *bin;
}Data;

struct node{
    int freq;
    char ch;
    char bin;
    struct node *left;
    struct node *right;
};

struct node *mergesort(struct node *);
struct node *merge(struct node *, struct node *);

struct node* getNode(char x, int y){
    struct node *temp;
    temp = (struct node*) malloc(sizeof(struct node));
    temp->ch = x;
    temp->freq = y;
    temp->bin = '0';
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

struct node* getSubtree(struct node *head){
    struct node *temp, *temp_1, *temp_2, *temp_3;
    temp = (struct node*) malloc(sizeof(struct node));
    temp_1 = (struct node*) malloc(sizeof(struct node));
    temp_2 = (struct node*) malloc(sizeof(struct node));
    temp_3 = (struct node*) malloc(sizeof(struct node));
    
    if(head->right->ch == '\0')
        head->right->left->bin = '1';
    else
        head->right->bin = '1';
    
    temp->ch = '\0';
    temp->freq = head->freq + (head->right->freq);
   
    temp->bin = '0';
    temp_1 = head->right;
    
    head->right = NULL;
    
    if(head->ch == '\0')
        temp->left = head->left;
    else
        temp->left = head; 
    
    temp_2 = temp_1->right;
    
    temp_1->right = NULL;
    if(temp_1->ch == '\0')
        temp->right = temp_1->left;
    else
        temp->right = temp_1; 
        
    temp_1 = NULL;
    head = NULL;
 
    temp_3->freq = temp->freq;
    
    temp_3->ch = '\0';
    temp_3->bin = '0';
    
    temp_3->right = temp_2;
    temp_3->left = temp;
    
    return temp_3;
}

struct node* HuffmanTree(struct node *head, int m){
    while(m){
         /* sort characters in ascending order of their frequency.*/
        head = mergesort(head);
        head = getSubtree(head);
        m--;
    }
    return head->left;
}

int x =0;
Data* Traversal(struct node *head, Data *data, char *arr, int size){
    
    if(head->right == NULL){
        size++;
        data[x].bin = (char*) realloc(arr, (size+1)* sizeof(char));
        data[x].bin[size-1] = head->bin;
        data[x].bin[size] = '\0';
        data[x].ch = head->ch;
        printf("\n%c = ", data[x].ch);
        for(int i=1; data[x].bin[i]!='\0'; i++)
		     printf("%c", data[x].bin[i]);
        x++;
    }
    
    else{
        size++;
        arr = (char*) realloc(arr, size* sizeof(char));
        arr[size-1] = head->bin;
        data = Traversal(head->left, data, arr, size);
        data = Traversal(head->right, data, arr, size);
    }
    return data;
}

char *inputString(FILE* fp, size_t size, int *n){
//The size is extended by the input with the value of the provisional
    char *str;
    int ch;
    size_t len = 0;
    str = realloc(NULL, sizeof(*str)*size);//size is start size
    if(!str)return str;
    while(EOF!=(ch=fgetc(fp)) && ch != '\n'){
        str[len++]=ch;
        if(len==size){
            str = realloc(str, sizeof(*str)*(size+=16));
            if(!str)return str;
        }
    }
    str[len++]='\0';
    *n = len;
    return realloc(str, sizeof(*str)*len);
}

int main(){
    char *arr;
    int n=0;
    printf("input string : ");
    arr = inputString(stdin, 10, &n);
    
    int i, j, m, Count, FreqArr[n];
  for(i=0;i<n;i++){
        FreqArr[i]=-1;
    }
    m=0;
    for (i = 0; i < (n-1); i++){
	    Count = 1;
		for(j = i+1; j < (n-1); j++){
    		if(arr[i] == arr[j]){
    			Count++;
    			FreqArr[j] = 0;
    		}
    	}
    	if(FreqArr[i] != 0){
    		FreqArr[i] = Count;
    		m++;
    	  }
	}

  printf("\nFrequency of All the Elements in this Array are : \n");
  struct node *head, *temp, *current;

  head = NULL;
 for (i = 0; i < (n-1); i++){
  	if(FreqArr[i] != 0){
  	    if(head == NULL){
  	        head = getNode(arr[i], FreqArr[i]);
  	        current = head;
  	      }
  	    else{
  	        temp = getNode(arr[i], FreqArr[i]);
  	        current->right = temp;
  	        current = temp;
  	    }
       }
  }
  free(arr);
  temp = head;
  while(temp != NULL){
      printf("%c occurs %d times\n", temp->ch, temp->freq);
      temp = temp->right;
  }

head = HuffmanTree(head, m-1);

head->bin = '\0';
char *array;
Data *data;
data = (Data*) malloc(m*sizeof(Data));
array = (char*) calloc(1, sizeof(char));
printf("\nHuffman Coding::\n");
data = Traversal(head, data, array, 0);

free(current);
free(temp);
free(head);
return 0;
}

/* preform merge sort on the linked list */
struct node *mergesort(struct node *head) {
 struct node *head_one;
 struct node *head_two;
 
 if((head == NULL) || (head->right == NULL))
  return head;
 
 head_one = head;
 head_two = head->right;
 while((head_two != NULL) && (head_two->right != NULL)) {
  head = head->right;
  head_two = head->right->right;
 }
 head_two = head->right;
 head->right = NULL;
 
 return merge(mergesort(head_one), mergesort(head_two));
}

/*Merge Function for above Merge Sort function */
struct node *merge(struct node *head_one, struct node *head_two) {
 struct node *head_three;
 
 if(head_one == NULL)
  return head_two;
 
 if(head_two == NULL)
  return head_one;
 
 if(head_one->freq < head_two->freq) {
  head_three = head_one;
  head_three->right = merge(head_one->right, head_two);
 }
 else {
  head_three = head_two;
  head_three->right = merge(head_one, head_two->right);
 }
 
 return head_three;
}
