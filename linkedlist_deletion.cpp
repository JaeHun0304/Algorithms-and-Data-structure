
#include <iostream>

struct Node{
	int data;
	Node *next;
};

void insertfront(Node** head_ref, int new_data){ // Node** Pointer to a pointer to structure Node

	Node* new_node = new (Node);

	new_node -> data = new_data;
	new_node -> next = *head_ref;

	(*head_ref) = new_node;

}

void deletelist(Node** head_ref, int n){	//delete list located on the index n

	Node* prev_node = new(Node);
	Node* temp = new(Node);

	prev_node = *head_ref;

	for(int i =0; i < n-1; i++){
		prev_node = prev_node -> next;
	}

	if(prev_node == NULL)
		return;

	temp = prev_node -> next;
	prev_node -> next = temp -> next;

	delete temp;

}

void clearmemory(Node** head_ref){

	Node* current_node = *head_ref;
	Node* next_node;

	while(current_node != NULL){
		next_node = current_node -> next;
		delete current_node;
		current_node = next_node;
	}

	*head_ref = NULL;
}


int main(void){

	Node* head = new (Node);

	head -> data = 1;
	head -> next = NULL;

	insertfront(&head, 3);
	insertfront(&head, 5);
	std::cout << head -> data << " " << head -> next -> data << " " << head -> next -> next -> data << "\n";
	deletelist(&head, 1);
	std::cout << head -> data << " " << head -> next -> data << "\n";

	clearmemory(&head);
	
	if(head == NULL)
		std::cout << "Empty linked list";	//Test if the clearmemory function works properly

	return 0;
}