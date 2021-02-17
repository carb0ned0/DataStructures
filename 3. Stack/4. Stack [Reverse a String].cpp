// Stack : Implementation using Linked List

#include <stack>			// stack from standard template library
#include <iostream>

void Reverse(char *string, int size);

int main()
{
	char string[51];
	printf(" Enter a string : ");
	gets_s(string);
	Reverse(string, strlen(string));
	printf("Reversed string : %s\n", string);
}

void Reverse(char *S,int size)
{
	std::stack<char> Stack;

	for (int i = 0; i < size; i++)
	{
		Stack.push(S[i]);
	}

	for (int i = 0; i < size; i++)
	{
		S[i] = Stack.top();
		Stack.pop();
	}
}


//
//
//struct Node
//{
//	int data;
//	struct Node* link;
//};
//
//int Top();
//void Pop();
//int Menu();
//int Input();
//void Push(int);
//bool IsEmpty();
//void Reverse();
//void CheckTop();
//void CheckPop();
//bool Continue();
//void Choose(int);
//void PrintStack();
//void CheckReverse();
//
//struct Node* topNode = NULL;
//
//void CheckReverse()
//{
//	if (IsEmpty())
//	{
//		printf("\n\t Oops, looks like Stack is Empty");
//		return;
//	}
//	else
//	{
//		Reverse();
//		PrintStack();
//	}
//}
//
//void Reverse()
//{
//	struct Node* currentNode, * previousNode, * nextNode;
//	currentNode = topNode;
//	previousNode = NULL;
//	while (currentNode != NULL)
//	{
//		nextNode = currentNode->link;
//		currentNode->link = previousNode;
//		previousNode = currentNode;
//		currentNode = nextNode;
//	}
//	topNode = previousNode;
//}
//
//bool Continue()
//{
//	char YesOrNo;
//	printf("\n Wanna continue (Y/n) : ");
//	std::cin >> YesOrNo;
//	if (YesOrNo == 'Y' || YesOrNo == 'y')
//	{
//		system("CLS");
//		return true;
//	}
//	else if (YesOrNo == 'N' || YesOrNo == 'n')
//	{
//		printf("\n Thanks for using this Program :)\n");
//		return false;
//	}
//	else
//	{
//		system("CLS");
//		printf("\n\t Sorry Bro, Only Y/N or y/n are allowed, Try Again!");
//		if (Continue())
//			Choose(Menu());
//	}
//}
//
//int Input()
//{
//	int data = 0;
//	printf("\t Enter the number : ");
//	std::cin >> data;
//	return data;
//}
//
//void Choose(int choice)
//{
//	switch (choice)
//	{
//	case 1:
//		Push(Input());
//		if (Continue())
//			Choose(Menu());
//		break;
//	case 2:
//		CheckPop();
//		if (Continue())
//			Choose(Menu());
//		break;
//	case 3:
//		CheckTop();
//		if (Continue())
//			Choose(Menu());
//		break;
//	case 4:
//		if (IsEmpty())
//			printf("\n\t Yup, Stack is empty");
//		else
//			printf("\n\t Nope, Stack is not empty");
//
//		if (Continue())
//			Choose(Menu());
//		break;
//	case 5:
//		CheckReverse();
//		if (Continue())
//			Choose(Menu());
//		break;
//	case 6:
//		PrintStack();
//		if (Continue())
//			Choose(Menu());
//		break;
//	case 7:
//		printf("\n Thanks for using this Program :)\n");
//		break;
//	default:
//		system("CLS");
//		printf("\n\t Oops, looks like you've entered something this program does't get it\n");
//		if (Continue())
//			Choose(Menu());
//		break;
//	}
//}
//
//void PrintStack()
//{
//	if (IsEmpty())
//	{
//		printf("\n\t Oops, looks like Stack is Empty");
//		return;
//	}
//	printf("\n\t Elements :");
//	struct Node* printingNode = topNode;
//	while (printingNode != NULL)
//	{
//		printf(" %d", printingNode->data);
//		printingNode = printingNode->link;
//	}
//}
//
//int Menu()
//{
//	int choice = 0;
//	printf("\n Stack Operations : ");
//	printf("\n\t 1. Push into stack");
//	printf("\n\t 2. Pop from Stack");
//	printf("\n\t 3. Top of the Stack ");
//	printf("\n\t 4. Is Stack Empty ");
//	printf("\n\t 5. Reverse the Stack ");
//	printf("\n\t 6. Print all the Elements of stack ");
//	printf("\n\t 7. Exit");
//	printf("\n\t Enter your Choice : ");
//	std::cin >> choice;
//	return choice;
//}
//
//void CheckTop()
//{
//	if (IsEmpty())
//	{
//		printf("\n\t Oops, looks like Stack is Empty");
//		return;
//	}
//	printf("\n\t Top : %d", Top());
//}
//
//void CheckPop()
//{
//	if (IsEmpty())
//	{
//		printf("\n\t Oops, looks like Stack is Empty");
//	}
//	else
//	{
//		printf("\n\t %d Poped fom Stack ", topNode->data);
//		Pop();
//	}
//}
//
//void Pop()
//{
//	struct Node* node;
//	node = topNode;
//	topNode = topNode->link;
//	free(node);
//}
//
//void Push(int data)
//{
//	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//	newNode->data = data;
//	newNode->link = topNode;
//	topNode = newNode;
//}
//
//int Top()
//{
//	return topNode->data;
//}
//
//bool IsEmpty()
//{
//	if (topNode == NULL)
//		return true;
//	else
//		return false;
//}
