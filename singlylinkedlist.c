
#include <stdio.h>
#include <stdlib.h>

struct node{
	int val;
	struct node *next;
};

struct list{
	struct node* head;
}; // Typen Definition 


void initList(struct list *listA){
	listA->head = NULL;
}

void append(struct list *listA, int val){
	
	if (listA->head == NULL){
		listA->head = malloc(sizeof(struct node)); //malloc fügt Platz hinzu in der Länge eines struct node
		listA->head->val = val; //listA->head->val ist ein integer! Achtung schauen int = int
		listA->head->next = NULL;
	}
	else{
		struct node* p = listA->head; // Var 2 für listA->head
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = malloc(sizeof(struct node));
		p->next->val = val;
		p->next->next = NULL;
	}
}

void reverse(struct list *listA){
	struct node* prev   = NULL;
	struct node* current = listA->head;
	struct node* next;
	
	while (current != NULL){
		next  = current->next;
		current->next = prev;
		prev = current;
		current = next;
   }
	
   listA->head = prev;
}


void print(struct list *listA){
	
	struct node *p = listA->head;
	printf("[ ");
	while(p != NULL){
		printf("%d ", p->val);
		p = p->next;
	}
	printf("]\n");
}

void deleteLast(struct list *listA){
	struct node *p = listA->head;
	struct node *toDelLast;
	
	if(listA->head == NULL){
		printf("There is no element in the list.");
	}
	
	else{
		toDelLast = listA->head;
		p = listA->head;
		while(toDelLast->next != NULL){
			p = toDelLast;
			toDelLast = toDelLast->next;
		}
		if(toDelLast == listA->head){
			listA->head = NULL;
		}
		else{
			p->next=NULL;
		}
		
		free(toDelLast);
	}
	
}

void del(struct list *listA, int i){
	
	struct node *p = listA->head;
	int count = 1;
	if (i == 0) {
		listA->head = p->next;
		free(p);
	}
	
	else{
		while(count != i){
		p = p->next;
		count++;
	}
	struct node *c = p->next;
	p->next = c->next;
	free(c);
	}
}

/* Function to delete the entire linked list */

void clear(struct list *listA){
	
	struct node* current = listA->head;
	struct node* next;
	
	while (current != NULL){
		next = current->next;
		free(current);
		current = next;
	}
	listA->head = NULL;
}

void max(struct list *listA){
    // start at the root
    int max;
    struct node *currentNode = listA->head;

    if (currentNode == NULL){
    	printf("The list is empty.");
	}

    // initialize the max value to the first node
    max = currentNode->val;
    
    // loop through the list
    for (currentNode = currentNode->next; currentNode != NULL; currentNode = currentNode->next){
        
		if (currentNode->val > max){
        	max = currentNode->val;	
		}
		
    }
    printf("Max value is: %d", max); 
}


int main(void){

	
	int n = 7, A[] = {9, 4, 5, 3, 1, 2, 0}, i = 0;
	struct list* new_list = malloc(sizeof(struct list)); // Gründung, Definition der Liste new_list
	
	initList(new_list);
	for (i = 0; i < n; i++){
		append(new_list, A[i]);
	}
	print(new_list); // 1.
	reverse(new_list); // 2.
	print(new_list); // 3.
	del(new_list, 6); // 5.
	del(new_list, 3); // 5.
	del(new_list, 0); // 5.
	print(new_list); // 6.
	deleteLast(new_list); // 7.
	print(new_list); // 8.
	max(new_list); // 9.
	clear(new_list); // 10.
	printf("\n");
	print(new_list); // 11.
	
	
	return 0;
}
