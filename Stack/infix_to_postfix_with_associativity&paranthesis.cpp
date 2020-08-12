// Infix to Postfix with Associativity and Paranthesis
// Algorithm a bit different from normal conversion and involves InStack OutStack precedence

#include <cstddef>
#include <iostream>
#include<stack>
using namespace std;

char* infix_to_postfix(char* infix);
bool is_operand(char c);
int in_stack_precedence(char c);
int out_stack_precedence(char c);

int main()
{
	char infix[] = "((a+b)*c)-d^e^f";

	cout << infix_to_postfix(infix) << endl;
}

char* infix_to_postfix(char* infix)
{
	stack<char> stack;
	char* postfix = new char[strlen(infix) + 1];
	int i = 0, j = 0;

	while (infix[i] != '\0')
	{
		if (is_operand(infix[i]))
			postfix[j++] = infix[i++];
		else
		{
			if (stack.empty() || out_stack_precedence(infix[i]) > in_stack_precedence(stack.top()))
				stack.push(infix[i++]);
			// they'll be equal when infix[i] is ')' and stack.top() is '(' which we don't want to push inside stack
			else if (out_stack_precedence(infix[i]) == in_stack_precedence(stack.top()))
			{
				stack.pop();
				i++;
			}
			else
			{
				postfix[j++] = stack.top();
				stack.pop();
			}
		}
	}

	while (!stack.empty())
	{
		postfix[j++] = stack.top();
		stack.pop();
	}

	postfix[j] = '\0';

	return postfix;
}

bool is_operand(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/' ||
		c == '^' || c == '(' || c == ')')
	{
		return false;
	}

	return true;
}

int in_stack_precedence(char c)
{
	if (c == '+' || c == '-') {
		return 2;
	}
	else if (c == '*' || c == '/') {
		return 4;
	}
	else if (c == '^') {
		return 5;
	}
	else if (c == '(') {
		return 0;
	}
	return -1;
}

int out_stack_precedence(char c)
{
	if (c == '+' || c == '-') {
		return 1;
	}
	else if (c == '*' || c == '/') {
		return 3;
	}
	else if (c == '^') {
		return 6;
	}
	else if (c == '(') {
		return 7;
	}
	else if (c == ')') {
		return 0;
	}
	return -1;
}