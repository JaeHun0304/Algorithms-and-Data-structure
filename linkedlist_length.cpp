
#include <iostream>

struct Node{
	int data;
	Node* next;
};

int lengthlist(Node** head_ref){
	int counter = 0;
	Node* current_node = *head_ref;

	while(current_node != NULL){
		current_node = current_node -> next;
		counter++;
	}

	return counter;
}

void insertfront(Node** head_ref, int new_data){ // Node** Pointer to a pointer to structure Node

	Node* new_node = new (Node);

	new_node -> data = new_data;
	new_node -> next = *head_ref;

	(*head_ref) = new_node;

}

int main(){

	Node* head;
	head = new (Node);

	head -> data = 1;
	head -> next = NULL;

	insertfront(&head, 3);
	insertfront(&head, 5);
	insertfront(&head, 7);

	std::cout << lengthlist(&head);

	return 0;
}