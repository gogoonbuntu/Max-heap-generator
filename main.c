#include <stdio.h>
#include <ctype.h>

int insertf(void);
int deletef(void);
int retrf(void);
int keyf(void);
int printAllf(void);


int main(void) {
	char menu;
	while(1){
		printf("\n*********** MENU ***********\n");
		printf("I : Insert new element into queue\n");
		printf("D : Delete element with largest key from queue.\n");
		printf("R : Retrieve element with largest key from queue\n");
		printf("K : Increase key of elecment in queue.");
		printf("P : Print out all elements in queue.\n");
		printf("Q : Quit\n\n");
		printf("Choose menu :  ");
		scanf("%c", &menu);
		menu = tolower(menu);
		switch(menu) {
			case 'i' : insertf();
			case 'd' : deletef();
			case 'r' : retrf();
			case 'k' : keyf();
			case 'p' : printAllf();
			case 'q' : return 0;
			default: continue;
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
	printf("\nNew element [%s, %d] is inserted", name, keyv);
}

int deletef(void){
	char name[30];
	int keyv;
	printf("\n[%s, %d] is deleted", name, keyv);
}

int keyf(void){

}

int printAllf(void){

}