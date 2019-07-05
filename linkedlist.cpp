
#include <cstdlib>
#include <iostream>


struct Node{
	int data;
	Node* next;
};

int main(){

	Node* head;
	Node* middle;
	Node* tail;

	head = (Node*)malloc(sizeof(Node));
	middle = (Node*)malloc(sizeof(Node));
	tail = (Node*)malloc(sizeof(Node));

	head -> data = 1;
	head -> next = middle;

	middle -> data = 2;
	middle -> next = tail;

	tail -> data = 3;
	tail -> next = NULL;

	std::cout << head -> data << " " << head -> next -> data << " " << head -> next -> next -> data;
}