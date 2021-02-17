// LinkedList : Printing by Recursion

#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

void PrintFarward(struct Node* currentNode);
void PrintBackward(struct Node* currentNode);
struct Node* Insert(int data, struct Node* headNode);

int main()
{
	struct Node* headNode = NULL;
	
	headNode = Insert(2, headNode);
	headNode = Insert(4, headNode);
	headNode = Insert(6, headNode);
	headNode = Insert(5, headNode);
	headNode = Insert(1, headNode);
	headNode = Insert(3, headNode);
	headNode = Insert(7, headNode);
	headNode = Insert(8, headNode);

	printf("\n Farward List : ");
	PrintFarward(headNode);
	printf("\n");

	printf("\n Backward List : ");
	PrintBackward(headNode);
	printf("\n");
}

struct Node* Insert(int data, struct Node* headNode)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	if (headNode == NULL)	
		headNode = newNode;
	else {
		Node* nextNode = headNode;
		while (nextNode->next != NULL)	
			nextNode = nextNode->next;
		nextNode->next = newNode;
	}
	return headNode;
}

void PrintFarward(struct Node* currentNode)
{
	if (currentNode == NULL)					// Exiting when List Ended
		return;
	printf(" %d", currentNode->data);
	PrintFarward(currentNode->next);			// Recursion
}

void PrintBackward(struct Node* currentNode)
{
	if (currentNode == NULL)					// Exiting when List Ended
		return;
	PrintBackward(currentNode->next);			// Recursion
	printf(" %d", currentNode->data);

}
