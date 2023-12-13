#include <bits/stdc++.h>
#include <C:\Users\Tejas Ingle\OneDrive\Desktop\PICT Study\DSA\PracticalExam\InfixtoPost_2\stackADT.cpp>
using namespace std;

int prec(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' && c == '/')
    {
        return 2;
    }
    else if (c == '+' && c == '-')
    {
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
            while (!st.isempty() && st.peek() != ')')
            {
                res += st.pop();
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
            }
            st.push(s[i]);
        }
    }
    while (!st.isempty())
    {
        res += st.pop();
    }

    return res;
}

string infixtoprefix(string s){
    stackADT<char> st;
    string res;

    reverse(s.begin(),s.end());
    for (int i = 0; i < s.length(); i++)
    {
        if(isalpha(s[i])){
            st.push(s[i]);
        }
        else if(s[i]=='('){
            res+=s[i];
        }
        else if(s[i]==')'){
            while (!st.isempty()&& st.peek()!='(')
            {
               res+=st.pop();
            }
            if(!st.isempty()){
                st.pop();
            }
        }
        else{
            while (!st.isempty()&&prec(st.peek())>=prec(s[i]))
            {
                res+=st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.isempty())
    {
        res+=st.pop();
    }

    reverse(res.begin(),res.end());
    return res;
    
    
}

int postfix_Evalution(string s){
    stackADT<int> st;
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i]>='0'&&s[i]<='9'){
            st.push(s[i]-'0');
        }
        else{
            int op2 = st.pop();
            int op1 = st.pop();

            switch (s[i])
            {
            case '+':
                st.push(op1+op2);
                break;
            case '-':
                st.push(op1-op2);
                break;
            case '*':
                st.push(op1*op2);
                break;
            case '/':
                st.push(op1/op2);
                break;
            
            default:
                break;
            }
        }
    }
    return st.peek();
    
}
int prefix_Evaluation(string s){
    stackADT<int> st;
    for (int i = s.length()-1; i >=0 ; i--)
    {
        if(s[i]>='0'&&s[i]<='9'){
            st.push(s[i]-'0');
        }
        else{
            int op1 = st.pop();
            int op2 = st.pop();

            switch (s[i])
            {
            case '+':
                st.push(op1+op2);
                break;
            case '-':
                st.push(op1-op2);
                break;
            case '*':
                st.push(op1*op2);
                break;
            case '/':
                st.push(op1/op2);
                break;
            
            default:
                break;
            }
        }
    }
    return st.peek();
    
}

int main(int argc, char const *argv[])
{
    string s = infixtoprefix("A+B");
    cout << s;

    int r = prefix_Evaluation("+58");
    cout<<r;
    return 0;
}
