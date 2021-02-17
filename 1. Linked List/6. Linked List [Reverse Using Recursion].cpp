// LinkedList : Reverse Using Recursion

#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};
struct Node* headNode;
void Print();
void Reverse(struct Node* currentNode);
struct Node* Insert(int data, struct Node* headNode);

int main()
{
	 headNode = NULL;

	headNode = Insert(2, headNode);
	headNode = Insert(4, headNode);
	headNode = Insert(6, headNode);
	headNode = Insert(5, headNode);
	headNode = Insert(1, headNode);
	headNode = Insert(3, headNode);
	headNode = Insert(7, headNode);
	headNode = Insert(8, headNode);

	printf("\n   Normal List : ");
	Print();

	printf("\n Reversed List : ");
	Reverse(headNode);
	Print();
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

void Print()
{
	struct Node* node = headNode;
	while (node != NULL)
	{
		printf(" %d", node->data);
		node = node->next;
	}
	printf("\t\t [ Printed using Print() ]\n");
}

void Reverse(struct Node* currentNode)
{
	if (currentNode->next == NULL)
	{
		headNode = currentNode;
		return;
	}
	Reverse(currentNode->next);
	struct Node* previousNode = currentNode->next;		// Line : 1
	previousNode->next = currentNode;					// Line : 2
	currentNode->next = NULL;							// Line : 3

	//		We can use this line insted of using line 1, 2, 3
	//		"currentNode->next->next = currentNode;"
	//		But for that case headNode should be Global and 
	//		Reverse() should return the modified version of headNode
}
