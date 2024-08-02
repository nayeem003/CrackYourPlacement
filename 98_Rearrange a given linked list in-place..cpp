// C++ implementation

#include <bits/stdc++.h>
using namespace std;

// Creating the structure for node
struct Node {
	int data;
	struct Node* next;
};

// Function to create newNode in a linkedlist
Node* newNode(int key)
{
	Node* temp = new Node;
	temp->data = key;
	temp->next = NULL;
	return temp;
}

// Function to print the list
void printlist(Node* head)
{
	while (head) {
		cout << head->data;
		if (head->next)
			cout << "->";
		head = head->next;
	}
	cout << endl;
}

// Function to rearrange
void rearrange(Node** head, Node* last)
{
	if (!last)
		return;
	// Recursive call
	rearrange(head, last->next);
	// (*head)->next will be set to NULL after
	// rearrangement. Need not do any operation further Just
	// return here to come out of recursion
	if (!(*head)->next)
		return;

	// Rearrange the list until both head and last meet or
	// next to each other.
	if ((*head) != last && (*head)->next != last) {
		Node* tmp = (*head)->next;
		(*head)->next = last;
		last->next = tmp;
		*head = tmp;
	}
	else {
		if ((*head) != last)
			*head = (*head)->next;
		(*head)->next = NULL;
	}
}

// Drivers Code
int main()
{
	Node* head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(5);

	// Print original list
	printlist(head);

	Node* tmp = head;

	// Modify the list
	rearrange(&tmp, head);

	// Print modified list
	printlist(head);
	return 0;
}

// This code is contributed by Aditya Kumar (adityakumar129)
