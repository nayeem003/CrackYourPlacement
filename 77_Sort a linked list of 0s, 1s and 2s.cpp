//C++ code to implement the above approach
#include <iostream>

// Define a structure for a node in a linked list
struct Node {
int data;
Node *next;
};

// Function to insert a new node at the end of the linked list
void push(Node **head, int data) {
Node *newNode = new Node();
newNode->data = data;
newNode->next = nullptr;

if (*head == nullptr) {
	*head = newNode;
	return;
}

Node *last = *head;
while (last->next != nullptr) {
	last = last->next;
}

last->next = newNode;
}

// Function to print the linked list
void printList(Node *head) {
Node *current = head;
while (current != nullptr) {
	std::cout << current->data << " ";
	current = current->next;
}
std::cout << std::endl;
}

// Function to sort the linked list containing 0's, 1's, and 2's
void sortList(Node *head) {
int count[3] = {0, 0, 0};

// Count the number of 0's, 1's, and 2's in the linked list
Node *current = head;
while (current != nullptr) {
	count[current->data]++;
	current = current->next;
}

// Overwrite the linked list with the sorted elements
current = head;
int i = 0;
while (current != nullptr) {
	if (count[i] == 0) {
	i++;
	} else {
	current->data = i;
	count[i]--;
	current = current->next;
	}
}
}

int main() {
Node *head = nullptr;

// Insert some elements into the linked list
	push(&head, 0); 
	push(&head, 1); 
	push(&head, 0); 
	push(&head, 2); 
	push(&head, 1); 
	push(&head, 1); 
	push(&head, 2); 
	push(&head, 1); 
	push(&head, 2); 

std::cout << "Linked List before Sorting: "<<std::endl;
printList(head);

sortList(head);

std::cout << "Linked List after Sorting: "<<std::endl;
printList(head);

return 0;
}
//This code is contributed by Veerendra Singh Rajpoot
