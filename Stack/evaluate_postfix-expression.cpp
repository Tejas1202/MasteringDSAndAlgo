// Evaluation of an postfix expression
#include <cstddef>
#include <iostream>
#include<stack>
using namespace std;

bool is_operand(char c);
int evaluate(char* postfix);

int main()
{
	char postfix[] = "234*+82/-";

	cout << "Result is: " << evaluate(postfix) << endl;
}

int evaluate(char* postfix)
{
	stack<int> stack;
	int i = 0;
	int x, y, result;

	for (int i = 0; postfix[i] != '\0'; i++)
	{
		// Have to subtract character zero (whose decimal is 48) as we want to store integer in the stack. We can't simply typecast it as 1 typecasted into int will be 49.
		// Therefore 1 - '0' is (49 - 48), and hence 1 is stored in the stack
		if (is_operand(postfix[i]))
			stack.push(postfix[i] - '0');
		else
		{
			// Order is important here
			y = stack.top();
			stack.pop();
			x = stack.top();
			stack.pop();

			switch (postfix[i])
			{
			case '+': result = x + y; break;
			case '-': result = x - y; break;
			case '*': result = x * y; break;
			case '/': result = x / y; break;
			}

			stack.push(result);
		}
	}

	return stack.top();
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