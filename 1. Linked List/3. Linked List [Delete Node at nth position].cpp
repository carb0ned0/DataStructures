// Linked List: Deleting a node at nth position
#include <stdio.h>
#include <malloc.h>

struct Node
{
	int data;
	struct Node* next;
};

struct Node* head;
void Insert(int data);						// Insert an Integer at end of list
void Delete(int position);					// Delete Node at given @position
void Print();								// Print all elements in the list

int main()
{
	head = NULL;

	Insert(2);
	Insert(4);
	Insert(6);
	Insert(5);								// List : 2, 4, 6, 5
	Print();

	int positionOfNodeToBeDeleted;
	printf("Enter the Position : ");
	scanf_s("%d", &positionOfNodeToBeDeleted);
	Delete(positionOfNodeToBeDeleted);
	Print();
}

void Insert(int data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = head;					//newNode->next = NULL;
	head = newNode;
}

void Delete(int position)
{
	struct Node* previousNode = head;
	if (position == 1)
	{
		head = previousNode->next;			// head now points to second Node
		free(previousNode);
		return;
	}
	for (int i = 0; i < position - 2; i++)			// priviousNode -> (n-1)th Node
	{
		previousNode = previousNode->next;
	}
	struct Node* nthNode = previousNode->next;		// nth Node
	previousNode->next = nthNode->next;				// (n+1)th Node
	free(nthNode);									// Delete nth Node via free()
}

void Print()
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
