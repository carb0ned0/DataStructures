// Doubly Linked List : Implementation

#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node* next;
	struct Node* previous;
};

struct Node* head;
void PrintForward();
void PrintBackward(struct Node* head);
void InsertAtHead(int data);
void InsertAtTail(int data);
void InsertAtPosition(int data, int position);				// Needed to be Done
void Delete(int data, int position);						// Needed to be Done
struct Node* GetNewNode(int data);

int main()
{
	head = NULL;
	printf("\n Print Forward  : ");

	InsertAtHead(2);	printf("\n\t   List : ");
	PrintForward();		printf("\t\t\t [InsertAtHead(2)] ");
	InsertAtHead(6);	printf("\n\t   List : ");
	PrintForward();		printf("\t\t\t [InsertAtHead(6)] ");
	InsertAtHead(8);	printf("\n\t   List : ");
	PrintForward();		printf("\t\t [InsertAtHead(8)] ");

	InsertAtTail(1);	printf("\n\t   List : ");
	PrintForward();		printf("\t\t [InsertAtTail(1)] ");
	InsertAtTail(4);	printf("\n\t   List : ");
	PrintForward();		printf("\t\t [InsertAtTail(4)] ");
	InsertAtTail(7);	printf("\n\t   List : ");
	PrintForward();		printf("\t\t [InsertAtTail(7)] ");

	printf("\n\n Print Backward : ");
	printf("\n\t   List : ");
	PrintBackward(head);	
	printf("\n");
}

void PrintBackward(struct Node* head)
{
	if (head == NULL)
		return;

	PrintBackward(head->next);
	printf(" %d", head->data);
}

void InsertAtTail(int data)
{
	struct Node* newNode = GetNewNode(data);
	if (head == NULL)
	{
		head = newNode;
		return;
	}
	struct Node* lastNode = head;
	while (lastNode->next != NULL)
		lastNode = lastNode->next;						// Went to end
	lastNode->next = newNode;							// then add Node
}

void InsertAtHead(int data)
{
	struct Node* newNode = GetNewNode(data);
	if (head == NULL)
	{
		head = newNode;
		return;
	}
	head->previous = newNode;								// Went to beginning
	newNode->next = head;									// then add Node
	head = newNode;
}

void PrintForward()
{
	struct Node* node = head;
	while (node != NULL)
	{
		printf(" %d", node->data);
		node = node->next;
	}
}

struct Node* GetNewNode(int data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	newNode->previous = NULL;
	return newNode;
}
