// Queue : Implementation Using Linked List

#include <stdio.h>
#include <iostream>
constexpr auto MAX_SIZE = 101;

struct Node
{
	int data;
	struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

int Menu();
int Rear();
int Input();
int Front();
void DeQueue();
bool IsEmpty();
bool Continue();
void Choose(int);
void CheckRear();
void CheckFront();
void PrintQueue();
void EnQueue(int);

int main()
{
	Choose(Menu());
}

bool Continue()
{
	char YesOrNo;
	printf("\n Wanna continue more (Y/n) : ");
	std::cin >> YesOrNo;
	if (YesOrNo == 'Y' || YesOrNo == 'y')
	{
		system("CLS");
		return true;
	}
	else if (YesOrNo == 'N' || YesOrNo == 'n')
	{
		printf("\n Thanks for using this Program :)\n");
		return false;
	}
	else
	{
		system("CLS");
		printf("\n\t Sorry Bro, Only Y/N or y/n are allowed");
		printf(" Give it a try Again");
		if (Continue())
			Choose(Menu());
	}
}

int Input()
{
	int data = 0;
	printf("\t Enter the number : ");
	std::cin >> data;
	return data;
}

void PrintQueue()
{
	if (IsEmpty())
	{
		printf("\n\t Oops, looks like Queue is Empty");
		return;
	}
	printf("\n\t Elements :");
	struct Node* printingNode = front;
	while (printingNode != NULL)
	{
		printf(" %d",printingNode->data);
		printingNode = printingNode->next;
	}
	printf("\n");
}

int Menu()
{
	int choice = 0;
	printf("\n Queue Operations by Linked List : ");
	printf("\n\t 1. Insert into Queue");
	printf("\n\t 2. Delete from Queue");
	printf("\n\t 3. Fornt of the Queue ");
	printf("\n\t 4. Rear of the Queue ");
	printf("\n\t 5. Print all the Elements of Queue ");
	printf("\n\t 6. Exit Program");
	printf("\n\t Enter your Choice : ");
	std::cin >> choice;
	return choice;
}

void Choose(int choice)
{
	switch (choice)
	{
	case 1:
		EnQueue(Input());
		if (Continue())
			Choose(Menu());
		break;
	case 2:
		DeQueue();
		if (Continue())
			Choose(Menu());
		break;
	case 3:
		CheckFront();
		if (Continue())
			Choose(Menu());
		break;
	case 4:
		CheckRear();
		if (Continue())
			Choose(Menu());
		break;
	case 5:
		PrintQueue();
		if (Continue())
			Choose(Menu());
		break;
	case 6:
		printf("\n Thanks for using this Program :)\n");
		break;
	default:
		printf("\n\t Oops, looks like you have choosen worng option");
		system("CLS");
		Menu();
		break;
	}
}

void EnQueue(int data)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = data;
	temp->next = NULL;
	if (front == NULL && rear == NULL)
	{
		rear = temp;
		front = rear;
		return;
	}
	rear->next = temp;
	rear = temp;
}

void DeQueue()
{
	struct Node* temp = front;
	if (front == NULL)
		return;
	if (front == rear)
	{
		rear = NULL;
		front = rear;
	}
	else
		front = front->next;

	printf("\n\t %d, Dequeued Successfully", temp->data);
	free(temp);
}

void CheckFront()
{
	if (IsEmpty())
	{
		printf("\n\t Oops, looks like Queue is Empty");
		return;
	}
	printf("\n\t Front : %d", Front());
}

int Front()
{
	return front->data;
}

void CheckRear()
{
	if (IsEmpty())
	{
		printf("\n\t Oops, looks like Queue is Empty");
		return;
	}
	printf("\n\t Rear : %d", Rear());
}

int Rear()
{
	return rear->data;
}

bool IsEmpty()
{
	if (front == NULL && rear == NULL)
		return true;
	else
		return false;
}
