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
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

Node *CreateExprTree(string postfix)
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
void Preorder(Node *root)

{
    if (root != nullptr)
    {
        cout << root->data << " ";
        Preorder(root->left);
        Preorder(root->right);
    }
}
void Postorder(Node *root)
{

    if (root != nullptr)
    {
        Postorder(root->left);
        Postorder(root->right);
        cout << root->data << " ";
    }
}

int main(int argc, char const *argv[])
{
    string postfix = "AB+CD-*";

    Node *root = CreateExprTree(postfix);

    cout << "Inorder Traversal: ";
    Inorder(root);
    cout << endl;

    cout << "Preorder Traversal: ";
    Preorder(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    Postorder(root);
    cout << endl;
    return 0;
}


//lavda