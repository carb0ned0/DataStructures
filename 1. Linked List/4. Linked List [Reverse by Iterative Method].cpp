// LinkedList : Reversing by Iterative Method

#include <stdio.h>
#include <malloc.h>

struct Node
{
	int data;
	struct Node* next;
};

void Print(struct Node* head);
struct Node* Insert(int data,struct Node* head);
struct Node* Reverse(struct Node* head);

int main()
{
	struct Node* head = NULL;
	
	head = Insert(2, head);
	head = Insert(4, head);
	head = Insert(6, head);
	head = Insert(8, head);
	Print(head);

	head = Reverse(head);
	printf("\n List Reversed !!\n\n");
	Print(head);
}
 
struct Node* Reverse(struct Node* head)
{
	struct Node* currentNode, * previousNode, * nextNode;
	currentNode = head;
	previousNode = NULL;
	while (currentNode != NULL)
	{
		nextNode = currentNode->next;
		currentNode->next = previousNode;
		previousNode = currentNode;
		currentNode = nextNode;
	}
	head = previousNode;
	return head;
}

struct Node* Insert(int data, struct Node* head)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = head;					//newNode->next = NULL;
	head = newNode;
	return head;
}

void Print(struct Node* head)
{
	struct Node* node = head;
	printf(" List : ");
	while (node != NULL)
	{
		printf(" %d", node->data);
		node = node->next;
	}
	printf("\n");
}
