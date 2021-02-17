// Queue : Implementation Using Array

#include <stdio.h>
#include <iostream>
constexpr auto MAX_SIZE = 101;

int Queue[MAX_SIZE];
int front = -1;
int rear = -1;

int Menu();
int Rear();
int Input();
int Front();
bool IsFull();
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
	for (int i = front; i <= rear; i++)
	{
		printf(" %d", Queue[i]);
	}
}

int Menu()
{
	int choice = 0;
	printf("\n Queue Operations : ");
	printf("\n\t 1. Insert into Queue");
	printf("\n\t 2. Delete from Queue");
	printf("\n\t 3. Fornt of the Queue ");
	printf("\n\t 4. Rear of the Queue ");
	printf("\n\t 5. Is Queue Empty ");
	printf("\n\t 6. Is Queue Full");
	printf("\n\t 7. Print all the Elements of Queue ");
	printf("\n\t 8. Exit Program");
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
		if (IsEmpty())
			printf("\n\t Yup, Queue is empty");
		else
			printf("\n\t Nope, Queue is not empty");

		if (Continue())
			Choose(Menu());
		break;
	case 6:
		if (IsFull())
			printf("\n\t Yup, Queue is full");
		else
			printf("\n\t Nope, Queue is not full");

		if (Continue())
			Choose(Menu());
		break;
	case 7:
		PrintQueue();
		if (Continue())
			Choose(Menu());
		break;
	case 8:
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
	if ((rear + 1) % MAX_SIZE == front)
		return;
	else if (IsEmpty())
	{
		rear = 0;
		front = rear;
	}
	else
		rear = (rear + 1) % MAX_SIZE;
	Queue[rear] = data;
}

void DeQueue()
{
	if (IsEmpty())
	{
		printf("\n\t Oops, looks like your Queue is Empty !");
		return;
	}
	else if (front == rear)
	{
		rear = -1;
		front = rear;
	}
	else
	{
		front = (front + 1) % MAX_SIZE;
	}
	printf("\n\t %d, Dequeued Successfully",Queue[front -1]);
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
	return Queue[front];
}

bool IsFull()
{
	if (rear == MAX_SIZE - 1)
		return true;
	else
		return false;
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
	return Queue[rear];
}

bool IsEmpty()
{
	if (front == -1 && rear == -1)
		return true;
	else
		return false;
}