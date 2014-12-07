#include <stdio.h>
#include <stdlib.h>

#define null NULL

typedef struct node{
	int key;
	struct node* next;
}Node;

typedef struct node* List;

typedef struct linkedlist {
	Node* ptrToHead;
	Node* ptrToTail;
} SLL;

Node* newNodeConstructor(){
	return malloc(sizeof(struct node));
}

Node* push(Node* headRef, int data){
	Node* newNode = newNodeConstructor();
	newNode->key = data;
	newNode->next = headRef;
	return newNode;
}

void printlist(struct node *head){
	/* using a for loop to print*/
	Node* current = NULL;
	for (current = head; current != NULL; current = current->next)
		printf("Data = %d\n", current->key);
	printf("End of List\n");
}

Node* prevToMaxNode(Node* h){
	Node* prevToMax = h;
	Node* max = h->next;
	Node* current = h->next;
	
	if(h == null)	return null;

	if(current){	//if current is not null
		while(current->next != null){
			if(current->next->key > max->key){
				prevToMax = current;
				max = current->next;
			}
			current = current->next;
		}
		//now check with the head - SPECIAL CASE
		if(max->key <= h->key)	prevToMax = null;
		return prevToMax;
	}
	return null;
}


int findMaxKey(Node* h){	
	Node* prevToMax = prevToMaxNode(h);
	if(prevToMax)	return prevToMax->next->key;
	else			return h->key;
}

//test max key for any node as the starting point
void testMaxKeyFinder(Node* h){
	Node* current = h;
	while(current != null){
		printf("For List starting with key = %3d, max key = %d \n",
				current->key, findMaxKey(current));
		current = current->next;
	}
	printf("-------TEST ENDS----------------------\n");
}

Node* removeMaxNode(Node **href){
	Node* h = *href;
	Node* pToMax = null;
	Node* return_max = null;
	
	pToMax = prevToMaxNode(h);

	//check for the head
	if(pToMax == null){
		return_max = h;
		*href = (*href)->next;	//update head
	}
	else{
		return_max = pToMax->next;
		pToMax->next = pToMax->next->next;//remove the link
	}
	return return_max;
}

int removeMaxKey(Node** href){
	Node* maxnode = null;
	maxnode = removeMaxNode(href);
	
	return	maxnode->key;
	
}


//remove the max key for any key as the starting point
void testMaxKeyRemove(Node** href){
	while(*href != null){
		printf("%d \n", removeMaxKey(href) );

	}	printf("-------TEST ENDS----------------------\n");
}


//DRIVER CODE
int main(){
	SLL mylist= {NULL, NULL};
	
	mylist.ptrToHead = push(mylist.ptrToHead, 2);
	mylist.ptrToHead = push(mylist.ptrToHead, 18);
	mylist.ptrToHead = push(mylist.ptrToHead, 3);
	mylist.ptrToHead = push(mylist.ptrToHead, 27);
	mylist.ptrToHead = push(mylist.ptrToHead, 15);
	mylist.ptrToHead = push(mylist.ptrToHead, 8);
	mylist.ptrToHead = push(mylist.ptrToHead, 10);
	mylist.ptrToHead = push(mylist.ptrToHead, 50);
	printlist(mylist.ptrToHead);
	
	
	//testMaxKeyFinder(mylist.ptrToHead);
	
	testMaxKeyRemove(&(mylist.ptrToHead));

	printlist(mylist.ptrToHead);
	return 0;
}
