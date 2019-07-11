
#include <iostream>
using namespace std;

typedef struct Listnode{
	string data;
	struct Listnode* link;
} listnode;

typedef struct{
	listnode* head;
} linkedlist_h;

linkedlist_h* createLinkedList(void){
	linkedlist_h* CL;
	CL = (linkedlist_h*)malloc(sizeof(linkedlist_h));
	CL->head = NULL;
	return CL;
}

void freeLinkedList(linkedlist_h* CL){
	listnode* p;
	p = CL->head;
	if(p == NULL)
		return;
	while(p->link != CL->head){
		free(p);
		p = p->link;
	}
}

void insertFirstNode(linkedlist_h* CL, string x){	//insert node in the first of circular linked list
	listnode* target; 
	listnode* temp;
	target = (listnode*)malloc(sizeof(listnode));
	target->data = x;
	target->link = NULL;

	if(CL->head == NULL){
		CL->head = target;
		target->link = target;
		return;
	}

	temp = CL->head;
	while(temp->link != temp){
		temp = temp->link;
	}
	target->link = temp->link;
	temp->link = target;
	CL->head = target;
}

void insertMiddleNode(linkedlist_h* CL, listnode* pre, string x){
	listnode* target;
	target->data = x;	
	if(CL->head == NULL){
		CL->head = target;
		target->link = target;
		return;
	}

	if(pre->link == CL->head){
		pre->link = target;
		target->link = CL->head;
		return;
	}

	target->link = pre->link;
	pre->link = target;

}

void deleteNode(linkedlist_h* CL, listnode* pre){
	listnode* target;
	target = pre->link;

	if(CL->head == NULL){
		return;
	}

	if(target == CL->head){
		free(target);
		CL->head = target->link;
		return;
	}

	free(target);
	pre->link = target->link;
}

void printList(linkedlist_h* CL){	//print all the current nodes in the linked list
	listnode* p;
	cout << "CL = (";
	p = CL->head;
	while(p != NULL){
		cout << p->data;
		p = p->link;
		if(p != NULL)
			cout << ", ";
	}
	cout << ")\n";
}

int main(){

	linkedlist_h* CL;
	CL = createLinkedList();

	insertFirstNode(CL, "Monday");
	insertFirstNode(CL, "Tuesday");
	insertFirstNode(CL, "Wednesday");
	printList(CL);

	return 0;
}