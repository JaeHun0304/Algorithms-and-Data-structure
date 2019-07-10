
#include <iostream>
#include <cstring>
using namespace std;

typedef struct Listnode{
	char data[10];
	struct Listnode* link;
} listnode;

typedef struct{
	listnode* head;
} linkedlist_h;

linkedlist_h* createLinkedList_h(void){	 //create empty linked list
	linkedlist_h* L;
	L = (linkedlist_h*)malloc(sizeof(linkedlist_h));
	L -> head = NULL;
	return L;
}

void freeLinkedList_h(linkedlist_h* L){	//free memory of all the list
	listnode* p;
	while(L->head != NULL){
		p = L->head;
		L->head = L->head->link;
		free(p);
		p=NULL;
	}
}

void addLastNode(linkedlist_h* L, char* x){	//Insert node in the last
	listnode* newNode;
	listnode* p;
	newNode = (listnode*)malloc(sizeof(listnode));
	strcpy(newNode->data, x);
	newNode->link=NULL;
	if(L->head == NULL){
		L->head = newNode;
		return;
	}
	p = L->head;
	while(p->link != NULL)
		p = p->link;
	p->link = newNode;
}

void reverse(linkedlist_h* L){	//change the oreder of the linked list in the reverse way
	listnode* p;
	listnode* q;
	listnode* r;
	p = L->head;
	q = NULL;
	r = NULL;

	while(p != NULL){
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}

	L->head = q;
}

void deleteLastNode(linkedlist_h* L){	//delete last node
	listnode* previous;
	listnode* current;
	previous = L->head;
	current = L->head->link;

	if(previous==NULL){
		return;
	}
	if(current==NULL){
		free(current);
		previous->link = NULL;
		return;
	}

	while(current->link != NULL){
		previous = current;
		current = current->link;
	}
	free(current);
	previous->link = NULL;

}

void deleteTargetNode(linkedlist_h* L, char* target){

	listnode* previous;
	listnode* current;
	previous = L->head;
	current = L->head->link;

	if(previous->data == target && current == NULL){
		L->head = NULL;
		free(previous);
		return;
	}

	if(current->data == target && current->link == NULL){
		previous->link = NULL;
		free(current);
		return;
	}

	while(current->data != target){
		previous = current;
		current = current->link;
	}
	previous->link = current->link;
	free(current);
}

void printList(linkedlist_h* L){	//print all the current nodes in the linked list
	listnode* p;
	cout << "L = (";
	p = L->head;
	while(p != NULL){
		cout << p->data;
		p = p->link;
		if(p != NULL)
			cout << ", ";
	}
	cout << ")\n";
}

int main(){

	linkedlist_h* L;
	L = createLinkedList_h();
	printList(L);

	addLastNode(L, "Monday");
	addLastNode(L, "Tuesday");
	addLastNode(L, "Wednesday");
	addLastNode(L, "Sunday");
	printList(L);

	deleteLastNode(L);
	printList(L);

	deleteTargetNode(L, "Wednesday");
	printList(L);

	reverse(L);
	printList(L);

	freeLinkedList_h(L);
	printList(L);

	return 0;
}