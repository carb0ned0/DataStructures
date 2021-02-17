// Stack : Implementation using Arrays

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
constexpr auto MAX_SIZE = 101;

int Stack[MAX_SIZE];
int top = -1;

void Pop();
int Top();
int Menu();
int Input();
void Choose(int);
bool IsEmpty();
void CheckTop();
bool Continue();
void PrintStack();
void Push(int);

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
		Pop();
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
		printf("\n\t Oops, looks like you have choosen worng option");
		system("CLS");
		Menu();
		break;
	}
}

void PrintStack()
{
	if (top == -1)
	{
		printf("\n\t Oops, looks like Stack is Empty");
		return;
	}
	printf("\n\t Elements :");
	for (int i = 0; i <= top; i++)
	{
		printf(" %d", Stack[i]);
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

void Push(int data)
{
	if (top == MAX_SIZE -1)
	{
		printf("\n\t Stack OverFlow !!");
		return;
	}
	else
		Stack[++top] = data;
}

void Pop()
{
	if (top == -1)
	{
		printf("\n\t Stack UnderFlow !!");
		return;
	}
	else
	{
		--top;
		printf("\n\t One Element Poped");
	}

}

void CheckTop()
{
	if (top == -1)
	{
		printf("\n\t Oops, looks like Stack is Empty");
		return;
	}
	printf("\n\t Top : %d", Top());
}

int Top()
{
	return Stack[top];
}

bool IsEmpty()
{
	if (top == -1)
		return true;
	else
		return false;
}
