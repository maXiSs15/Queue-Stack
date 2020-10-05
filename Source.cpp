#include <iostream>
#include <stack>
#include<string>
using namespace std;
string infixToPostfix(string exp);
float calcPostfix(string postfix);
int main()
{
	string exp;
	cout << "enter an infix expression as a string" << endl;
	cin >> exp;
	string postfix = infixToPostfix(exp);
	cout << postfix << endl;
	cout << calcPostfix(postfix) << endl;
	system("pause");
	return 0;
}
string infixToPostfix(string exp)
{
	string str;
	stack<char> stk;
	char ch;
	int j = 0;
	for (int i = 0; i < exp.size(); i++)
	{
		ch = exp[i];
		switch (ch)
		{
		case ')':
			while (stk.top() != '(')
			{
				str += stk.top();
				str += ' ';
				stk.pop();
			}
			stk.pop();

			break;
		case '(':
			stk.push(ch);
			break;

		case '-':
		case '+':
			while ((stk.top() == '*' || stk.top() == '/') &&
				!stk.empty())
			{
				str += stk.top();
				stk.pop();
			}
			stk.push(ch);
			break;

		case '*':
		case '/':
			stk.push(ch);
			break;
		default:
			str += ch;
			if (exp[i + 1] < '0' || exp[i + 1] > '9')
				str += ' ';
			break;
		}
	}
	while (!stk.empty()) {
		str += stk.top();
		stk.pop();
	}
	return str;
}
float calcPostfix(string postfix)
{
	stack
		<float> stk;
	char ch, ch1;
	float tmp1, tmp2;
	for
		(int i = 0; i < postfix.size(); i++)
	{
		ch = postfix
			[i + 1];
		ch1 = postfix[i];
		switch (ch1) {
		case'+':
			tmp1 = stk.top();
			stk.pop();
			tmp2 = stk.top();
			stk.pop();
			stk.push(tmp2 + tmp1);
			break;

		case '*':
			tmp1 = stk.top();
			stk.pop();
			tmp2 = stk.top();
			stk.pop();
			stk.push(tmp2 * tmp1);
			break;

		case'-':
			tmp1 = stk.top();
			stk.pop();
			tmp2 = stk.top();
			stk.pop();
			stk.push(tmp2 - tmp1);
			break;

		case'/':
			tmp1 = stk.top();
			stk.pop();
			tmp2 = stk.top();
			stk.pop();
			stk.push(tmp2 / tmp1);
			break;

		case ' ':
			break;

		default:
			float tmp = ch1 - '0';
			while (postfix[i + 1] >= '0' && postfix[i + 1] <= '9')
			{
				tmp = tmp * 10 + (int)(postfix[i + 1] - '0');
				i++;
			}
			stk.push(tmp);
			break;
		}
	}
	return stk.top();
}