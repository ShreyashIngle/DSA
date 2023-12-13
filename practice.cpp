#include <bits/stdc++.h>

using namespace std;

struct Node
{
    char data;
    Node *left;
    Node *right;
};

Node *createNode(char data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
}

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

Node *createExprTree(string postfix)
{
    stack<Node *> s;
    for (char c : postfix)
    {
        if (isOperator(c))
        {
            Node *right = s.top();
            s.pop();
            Node *left = s.top();
            s.pop();

            Node *newNode = createNode(c);
            newNode->left = left;
            newNode->right = right;
            s.push(newNode);
        }
        else
        {
            Node *operand = createNode(c);
            s.push(operand);
        }
    }
    return s.top();
}

void Inorder(Node *root)
{
    if (root != nullptr)
    {
        Inorder(root->left);
        cout << root->data << " ";
        Inorder(root->right);
    }
}

void inorderNonRecur(Node *root)
{
    stack<Node *> st;
    Node *current = root;
    while (!st.empty() || 
    current != nullptr)
    {
        if (current != nullptr)
        {
            st.push(current);
            current = current->left;
        }
        else
        {
            current = st.top();
            st.pop();
            cout << current->data << " ";
            current = current->right;
        }
    }
}
void preorderNonRecur(Node *root)
{
    stack<Node *> st;
    Node *current = root;
    while (!st.empty() || current != nullptr)
    {
        if (current != nullptr)
        {
            cout << current->data << " ";
            st.push(current);
            current = current->left;
        }
        else
        {
            current = st.top();
            st.pop();
            current = current->right;
        }
    }
}
void Preorder(Node *root)
{
    if (root != nullptr)
    {
        cout << root->data << " ";
        Inorder(root->left);
        Inorder(root->right);
    }
}
void Postorder(Node *root)
{
    if (root != nullptr)
    {
        Inorder(root->left);
        Inorder(root->right);
        cout << root->data << " ";
    }
}

int main(int argc, char const *argv[])
{
    Node* root;

    string postfix = "";

    cout<<"lavada: ";
    cin>>postfix;
    root = createExprTree(postfix);
    inorderNonRecur(root);
    return 0;
}
