//Linked List: Inserting a node at beginning
#include <stdio.h>
#include <malloc.h>

struct Node
{
	int data;
	struct Node* next;
};

void Insert(Node**, int);
void Print(Node*);

int main()
{
	struct Node* head = NULL;
	int x, i, n;							//Empty List
	printf("How many Numbers : ");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("Enter the Number :");
		scanf("%d", &x);
		Insert(&head, x);
		Print(head);
	}
}

void Insert(Node** pointerToHead, int x)
{
	Node* temp = (Node*)malloc(sizeof(struct Node));
	temp->data = x;			// (*temp).data = x; can be used too
	temp->next = *pointerToHead;
	*pointerToHead = temp;
}

void Print(Node* start)
{
	struct Node* temp = start;
	printf("List : ");
	while (temp != NULL)
	{
		printf(" %d", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
