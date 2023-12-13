#include <iostream>
#include <stack>
#include <cctype>
#include <C:\Users\Tejas Ingle\OneDrive\Desktop\PICT Study\DSA\PracticalExam\InfixtoPost_2\stackADT.cpp>
#include <algorithm>
using namespace std;

int prec(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        /* code */
        return 1;
    }
    else
    {
        return -1;
    }
}

string infixtopost(string s)
{
    stackADT<char> st;
    string res;

    for (int i = 0; i < s.length(); i++)
    {
        if (isalpha(s[i]))
        {
            res += s[i];
        }
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (!st.isempty() && st.peek() != '(')
            {
                res += st.pop();
                // st.pop();
            }
            if (!st.isempty())
            {
                st.pop();
            }
        }
        else
        {
            while (!st.isempty() && prec(st.peek()) >= prec(s[i]))
            {
                res += st.pop();
                // st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.isempty())
    {
        res += st.pop();
        // st.pop();
    }
    return res;
}

string infixtoprefix(string s)
{
    stackADT<char> st;
    string res;

    reverse(s.begin(), s.end());

    for (int i = 0; i < s.length(); i++)
    {
        if (isalpha(s[i]))
        {
            res += s[i];
        }
        else if (s[i] == ')')
        {
            st.push(s[i]);
        }
        else if (s[i] == '(')
        {
            while (!st.isempty() && st.peek() != ')')
            {
                res += st.pop();
                // st.pop();
            }
            if (!st.isempty())
            {
                st.pop();
            }
        }
        else
        {
            while (!st.isempty() && prec(st.peek()) >= prec(s[i]))
            {
                res += st.pop();
                //   st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.isempty())
    {
        res += st.pop();
        // st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

int postfix_Evalution(string s)
{
    stackADT<int> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            st.push(s[i] - '0');
        }
        else
        {
            int op2 = st.pop();
            int op1 = st.pop();

            switch (s[i])
            {
            case '+':
                st.push(op1 + op2);
                break;
            case '-':
                st.push(op1 - op2);
                break;
            case '*':
                st.push(op1 * op2);
                break;
            case '/':
                st.push(op1 / op2);
                break;
            default:
                break;
            }
        }
    }
    return st.peek();
}

int prefix_Evaluation(string s)
{
    stackADT<int> st;

    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            st.push(s[i] - '0');
        }
        else
        {
            int op1 = st.pop();
            int op2 = st.pop();

            switch (s[i])
            {
            case '+':
                st.push(op1 + op2);
                break;
            case '-':
                st.push(op1 - op2);
                break;
            case '*':
                st.push(op1 * op2);
                break;
            case '/':
                st.push(op1 / op2);
                break;
            default:
                break;
            }
        }
    }

    return st.peek();
}

int main()
{
    string expression;
    char choice;

    do
    {
        cout << "Menu:\n";
        cout << "1. Convert infix to postfix\n";
        cout << "2. Convert infix to prefix\n";
        cout << "3. Evaluate postfix expression\n";
        cout << "4. Evaluate prefix expression\n";
        cout << "5. Exit\n";
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice)
        {
        case '1':
            cout << "Enter infix expression: ";
            cin >> expression;
            cout << "Postfix expression: " << infixtopost(expression) << endl;
            break;

        case '2':
            cout << "Enter infix expression: ";
            cin >> expression;
            cout << "Prefix expression: " << infixtoprefix(expression) << endl;
            break;

        case '3':
            cout << "Enter postfix expression: ";
            cin >> expression;
            cout << "Postfix evaluation result: " << postfix_Evalution(expression) << endl;
            break;

        case '4':
            cout << "Enter prefix expression: ";
            cin >> expression;
            cout << "Prefix evaluation result: " << prefix_Evaluation(expression) << endl;
            break;

        case '5':
            cout << "Exiting the program.\n";
            break;

        default:
            cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != '5');

    return 0;
}
