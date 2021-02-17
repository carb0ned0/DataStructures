// Stack : Implementation using Linked List

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>

struct Node
{
	int data;
	struct Node* link;
};


int Top();
void Pop();
int Menu();
int Input();
void Push(int);
bool IsEmpty();
void Choose(int);
void CheckTop();
void CheckPop();
bool Continue();
void PrintStack();

struct Node* topNode = NULL;

int main()
{
	Choose(Menu());
}

bool Continue()
{
	char YesOrNo;
	printf("\n Wanna continue (Y/n) : ");
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

void Choose(int choice)
{
	switch (choice)
	{
	case 1:
		Push(Input());
		if (Continue())
			Choose(Menu());
		break;
	case 2:
		CheckPop();
		if (Continue())
			Choose(Menu());
		break;
	case 3:
		CheckTop();
		if (Continue())
			Choose(Menu());
		break;
	case 4:
		if (IsEmpty())
			printf("\n\t Yup, Stack is empty");
		else
			printf("\n\t Nope, Stack is not empty");

		if (Continue())
			Choose(Menu());
		break;
	case 5:
		PrintStack();
		if (Continue())
			Choose(Menu());
		break;
	case 6:
		printf("\n Thanks for using this Program :)\n");
		break;
	default:
		system("CLS");
		printf("\n\t Oops, looks like you've choosen the worng option\n");
		if (Continue())
			Choose(Menu());
		break;
	}
}

void PrintStack()
{
	if (topNode == NULL)
	{
		printf("\n\t Oops, looks like Stack is Empty");
		return;
	}
	printf("\n\t Elements :");
	struct Node* printingNode = topNode;
	while(printingNode != NULL)
	{
		printf(" %d", printingNode->data);
		printingNode = printingNode->link;
	}
}

int Menu()
{
	int choice = 0;
	printf("\n Stack Operations : ");
	printf("\n\t 1. Push into stack");
	printf("\n\t 2. Pop from Stack");
	printf("\n\t 3. Top of the Stack ");
	printf("\n\t 4. Is Stack Empty ");
	printf("\n\t 5. Print all the Elements of stack ");
	printf("\n\t 6. Exit");
	printf("\n\t Enter your Choice : ");
	std::cin >> choice;
	return choice;
}

void CheckTop()
{
	if (topNode == NULL)
	{
		printf("\n\t Oops, looks like Stack is Empty");
		return;
	}
	printf("\n\t Top : %d", Top());
}

void CheckPop()
{
	if (topNode == NULL)
	{
		printf("\n\t Oops, looks like Stack is Empty");
	}
	else
	{
		printf("\n\t %d Poped fom Stack ", topNode->data);
		Pop();
	}
}

void Pop()
{
	struct Node* node;
	node = topNode;
	topNode = topNode->link;
	free(node);
}

void Push(int data)
{
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->link = topNode;
	topNode = newNode;
}

int Top()
{
	return topNode->data;
}

bool IsEmpty()
{
	if (topNode == NULL)
		return true;
	else
		return false;
}
