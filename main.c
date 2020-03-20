#include <stdio.h>
#include <ctype.h>
#include <memory.h>
#include <stdlib.h>
#include <math.h>

#define LEFT(i) (2*i)
#define RIGHT(i) (LEFT(i)+1)

int insertf(void);
int deletef(void);
int retrf(void);
int keyf(void);
int printAllf(void);
void max_heapify(int* a, int b);
int max(int* a);
void swap(int* a, int b, int c);
void strcpyf(char* b, char* a);

int keys[10]; //heap array
char names[10][30];
int size = 0;
int i, j;
char menu;

int main(void) {
	while(1){
		menu = '\0';
		printf("\n\n*********** MENU ***********\n");
		printf("I : Insert new element into queue\n");
		printf("D : Delete element with largest key from queue.\n");
		printf("R : Retrieve element with largest key from queue\n");
		printf("K : Increase key of elecment in queue.\n");
		printf("P : Print out all elements in queue.\n");
		printf("Q : Quit\n\n");

		printf("Choose menu :  ");
		scanf(" %c", &menu);
		getchar();
		menu = tolower(menu);
		
		switch(menu) {
			default: break;
			case 'i' : insertf();break;
			case 'd' : deletef();break;
			case 'r' : retrf();break;
			case 'k' : keyf();break;
			case 'p' : printAllf();break;
			case 'q' : return 0;
		}
	}
}

int insertf(void){
	char name[30];
	int keyv;
	printf("\nEnter name of element: ");
	scanf("%s", name);
	printf("Enter key value of element: ");
	scanf("%d", &keyv);
	
	i=1;
	while(keys[i]!='\0'){
		if(keyv==keys[i]){
			printf("key already exist.\n");
			return 0;
		}
		i++;
	}
	size++;
	keys[size]=keyv;
	
	strcpyf(names[keyv], name);
	//printf("keyv : %d, value : %s\n", keys[size], names[keyv]);
	printf("\nNew element [%s, %d] is inserted\n", name, keyv);
	if(size>1)
		for(i=size/2; i>0; i--){
			max_heapify(keys, i);
		}

	return 0;
}

int deletef(void){
	char name[30]="";
	int keyv;
	keyv = keys[1];
	strcpyf(name, names[keys[1]]);
	int len = (int)strlen(name);
	for(i=1;i<=size;i++){
		swap(keys, i, i+1);
	}
	int t = keys[size+1];
	strcpy(names[t],"");
	keys[size+1]='\0';
	printf("\n[%s, %d] is deleted\n", name, keyv);
}

int retrf(void){
	int t = keys[1];
	printf("\n[%s, %d]\n", names[t], t);
}

int keyf(void){
	int chosen, newone, idx;
	printf("\nEnter index of element: ");
	scanf("%d", &chosen);
	
	i=1;
	while(keys[i]!='\0'){
		if(chosen==keys[i]){
			idx = i;
			break;
		} else	i++;
	}

	if(i>size){
		printf("%d does not exist.", chosen);
		return 0;
	}
	
	printf("\nEnter new key value: ");
	scanf("%d", &newone);

	i=1;
	while(keys[i]!='\0'){
		if(newone==keys[i]){
			printf("key already exist.\n");
			return 0;
		}
		i++;
	}

	keys[idx] = newone;
	strcpyf(names[newone], names[chosen]);
	strcpy(names[chosen], "");
	if(size>1)
	for(i=size/2; i>0; i--){
		max_heapify(keys, i);
	}
}

int printAllf(void){
	i=1;
	while(1){
		if(keys[i]!='\0'){
			printf("[");
			int t = keys[i];
			printf("%s, %d", names[t], t);
			printf("]");
			i++;
		} else {
			return 0;
		}
	}
}

void max_heapify(int* keys, int q){
	int l, r;
	int largest = q;
	l = LEFT(q);
	r = l + 1;

	
	if(l<=size && keys[l] > keys[q]){
		largest = l;
	}

	if(r<=size && keys[r] > keys[largest]){
		largest = r;
	}

	if(largest != q){
		swap(keys, q, largest);
		max_heapify(keys, largest);
	}
}

int max(int* a) {
	i=1;
	int maxn = a[i];
	while(a[i]!='\0'){
		i++;
		a[i]>maxn ? maxn=a[i] : maxn;
	}
	return maxn;
}

void swap(int* a, int b, int c){
	int t;
	t = a[b];
	a[b] = a[c];
	a[c] = t;
}

void strcpyf(char* b, char* a) {
	i=0;
	while(a[i]!='\0'){
		b[i] = a[i];
		i++;
	}
}