#include <iostream>

struct Node{
	int data;
	Node* next;
};


void insertfront(Node** head_ref, int new_data){ // Node** Pointer to a pointer to structure Node

	Node* new_node = new (Node);

	new_node -> data = new_data;
	new_node -> next = *head_ref;

	(*head_ref) = new_node;

}

void insertmiddle(Node* prev_node, int new_data){

	Node* new_node = new (Node);

	new_node -> data = new_data;
	new_node -> next = prev_node -> next;
	prev_node -> next = new_node;

}

void insertlast(Node** head_ref, int new_data){

	Node* new_node = new (Node);
	Node* last = *head_ref;

	new_node -> data = new_data;

	if((*head_ref) == NULL){
		new_node -> next = *head_ref;
		return;
	}

	while( last->next != NULL){
		last = last->next;
	}

	new_node -> next = NULL;
	last->next = new_node;
	return;

}

int main(){

	Node* head;
	head = new (Node);

	head -> data = 1;
	head -> next = NULL;

	insertfront(&head, 3);
	insertmiddle(head->next, 5);
	insertlast(&head, 7);
	std::cout << head -> next -> next -> next -> data;


	return 0;
}