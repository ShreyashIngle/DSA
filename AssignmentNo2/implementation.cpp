#include <iostream>
#include "stack.cpp"
using namespace std;

class expression
{

public:
	int precedence(char);
	string reverse(string);
	string infix_to_postfix(string);
	string infix_to_prefix(string);
	int postfix_eval(string);
};

struct values
{
	char variable;
	int var_val;
};

string expression::reverse(string s)
{
	string rev = "";
	for (char ch : s)
	{
		if (ch == '(')
		{
			rev = ')' + rev;
		}
		else if (ch == ')')
		{
			rev = '(' + rev;
		}
		else
		{
			rev = ch + rev;
		}
	}
	return rev;
}
int expression ::precedence(char ch)
{
	if (ch == '+' || ch == '-')
	{
		return 1;
	}
	else if (ch == '/' || ch == '*')
	{
		return 2;
	}
	else if (ch == '^')
	{
		return 3;
	}
	else
	{
		return -1;
	}
}

string expression ::infix_to_postfix(string s)
{
	stack<char> st;
	string postfix = "";

	for (char ch : s)
	{

		if (isalnum(ch))
		{
			postfix += ch;
		}
		else if (ch == '(')
		{
			st.push(ch);
		}
		else if (ch == ')')
		{
			while (st.isTop() != '(')
			{
				postfix += st.isTop();
				st.pop();
			}
			st.pop();
		}
		else
		{
			while (!st.isempty() && (precedence(ch) <= precedence(st.isTop())))
			{
				postfix += st.isTop();
				st.pop();
			}
			st.push(ch);
		}
	}
	while (!st.isempty())
	{
		postfix += st.isTop();
		st.pop();
	}

	return postfix;
}
string expression ::infix_to_prefix(string s)
{
	string exp = reverse(s);
	string prefix = reverse(infix_to_postfix(exp));
	return prefix;
}

int expression::postfix_eval(string exp)
{
	stack<int> st;
	struct values obj[10];
	int a, b, ans;

	for (int i = 0; i < exp.size(); i++)
	{
		char op = exp[i];

		if (op != '+' && op != '-' && op != '*' && op != '/')
		{
			cout << "Enter value of " << op << " ";
			obj[i].variable = op;
			cin >> obj[i].var_val;
			st.push(obj[i].var_val);
		}
		else
		{
			a = st.isTop();
			st.pop();
			b = st.isTop();
			st.pop();

			switch (op)
			{
			case '+':
				ans = a + b;

				break;
			case '-':
				ans = b - a;

				break;
			case '*':
				ans = a * b;

				break;
			case '/':
				ans = a / b;

				break;
			}
			st.push(ans);
		}
	}

	cout << "\nPostfix Evaluation = ";
	return st.isTop();
}

int main()
{
	expression obj;
	string exp = "";

	while (true)
	{
		cout << "\n1.Enter Expression\n2.Postfix\n3.Prefix\n4.Postfix Evaluate\n5.Exit\n\nEnter the choice: ";
		int choice;
		cin >> choice;
		string eval_exp = obj.infix_to_postfix(exp);
		switch (choice)
		{
		case 1:
			cout << "Enter Expression: ";
			cin >> exp;
			break;
		case 2:
			cout << "\nPOSTFIX = " << obj.infix_to_postfix(exp) << endl;
			break;
		case 3:
			cout << "\nPREFIX = " << obj.infix_to_prefix(exp) << endl;
			break;
		case 4:
			cout << obj.postfix_eval(eval_exp) << endl;
			break;
		case 5:
			exit(0);
			break;

		default:
			cout << "Invalid!!";
			break;
		}
	}
	return 0;
}
