#include <iostream>
using namespace std;

class LinkedList
{
private:
	struct Node
	{
		int data;
		struct Node *next;
	};
	struct Node *top;

public:
	LinkedList()
	{
		top = NULL;
	}
	void push(int);
	void pop();
	void display();
	void peek();
};

void LinkedList::push(int n)
{
	struct Node *temp = new Node();
	if (top == NULL)
	{
		temp->data = n;
		temp->next = NULL;
		top = temp;
	}
	else
	{
		temp->data = n;
		temp->next = top;
		top = temp;
	}
}

void LinkedList::pop()
{
	if (top == NULL)
	{
		cout << "Underflow" << endl;
		return;
	}
	else
	{
		struct Node *temp = top;
		top = top->next;
		delete temp;
		temp = NULL;
	}
}
void LinkedList::peek()
{
	if (top == NULL)
	{
		cout << "Empty" << endl;
	}
	else
	{
		cout << "Top element is: " << top->data << endl;
	}
}
void LinkedList::display()
{
	struct Node *temp = top;
	while (temp != NULL)
	{
		cout << temp->data << "->";
		temp = temp->next;
	}
	cout<<endl;
}

int main()
{
	LinkedList l1;
	while (1)
	{
		int ch;
		cout << "1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit" << endl;
		cout << "Enter your choice:\n";
		cin >> ch;
		switch (ch)
		{
		case 1:
			int n;
			cout << "Enter the element to be pushed:\n";
			cin >> n;
			l1.push(n);
			break;
		case 2:
			l1.pop();
			break;
		case 3:
			l1.peek();
			break;
		case 4:
			l1.display();
			break;
		case 5:
			cout << "Thank you \n";
			exit(0);
		}
	}
	return 0;
}
