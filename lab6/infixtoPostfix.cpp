#include "linkedlistStack.h"
#include <iostream>
#include<math.h>
using namespace std;

class ExpressionConverter
{
private:
	LinkedList st;
	string str;
	string ans;

public:
	ExpressionConverter() {
		st = LinkedList();
		str = "";
		ans = "";
	}

	void GetInfix();
	int precedence(char c);
	void convertInfixToPostfix();
	int PostfixEvaluation();
};
int ExpressionConverter::precedence(char c)
{

	if (c == '^')
		return 3;
	else if (c == '/' || c == '*')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}
void ExpressionConverter::GetInfix()
{

	cout << "Enter the infix expression: ";
	cin >> str;
}
void ExpressionConverter::convertInfixToPostfix()
{
		for (int i = 0; i < str.length(); i++)
		{
			char c = str[i];

			if (isalnum(c)) 
			{
				ans += c;
			}
			else if (c == '(')
			{
				st.push(c);
			}
			else if (c == ')')
			{
				while (!st.isempty() && st.peek() != '(')
				{
					ans += st.pop();
				}
				st.pop(); 
			}
			else
			{
				while (!st.isempty() && precedence(c) <= precedence(st.peek()))
				{
					ans += st.pop();
				}
				st.push(c);
			}
		}

		while (!st.isempty())
		{
			ans += st.pop();
		}
	

		cout << "Postfix Expression: " << ans << endl;

}
int ExpressionConverter::PostfixEvaluation()
{
	LinkedList evalStack; // Stack for evaluation
	int operand1, operand2;

	for (char c : ans)
	{
		if (isdigit(c)) 
		{
			evalStack.push(c - '0'); // Convert a character to int
		}
		else
		{
			int operand2 = evalStack.pop();
			int operand1 = evalStack.pop();

			switch (c)
			{
			case '+':
				evalStack.push(operand1 + operand2);
				break;
			case '-':
				evalStack.push(operand1 - operand2);
				break;
			case '*':
				evalStack.push(operand1 * operand2);
				break;
			case '/':
				evalStack.push(operand1 / operand2);
				break;
			case '^':
				evalStack.push(pow(operand1, operand2));
				break;
			}
		}
	}

	return evalStack.pop(); 

}

int main()
{
	ExpressionConverter expr;
	while(1)
	{
		int choice;
		cout << "1. Convert Infix Expression to Postfix Expression" << endl;
		cout << "2. Evaluate Postfix Expression" << endl;
		cout << "3. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			expr.GetInfix();
			break;
		case 2:
			expr.convertInfixToPostfix();
			break;
		case 3:
		    expr.PostfixEvaluation();
			break;
		case 4:
			cout << "Exiting" << endl;
			return 0;
		}
	}
}
