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

// Recursion
void Inorder(Node *root)

{
    if (root != nullptr)
    {
        Inorder(root->left);
        cout << root->data << " ";
        Inorder(root->right);
    }
}

// NonRecursion
void inorderNonRecur(Node *root)
{
    stack<Node *> st;
    Node *current = root;

    while (!st.empty() || current != nullptr)
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

void Preorder(Node *root)

{
    if (root != nullptr)
    {
        cout << root->data << " ";
        Preorder(root->left);
        Preorder(root->right);
    }
}
// NonRecur
void preorderNonRecur(Node *root)
{
    stack<Node *> st;
    Node *current = root;

    while (current != nullptr || !st.empty())
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

void Postorder(Node *root)
{

    if (root != nullptr)
    {
        Postorder(root->left);
        Postorder(root->right);
        cout << root->data << " ";
    }
}
// Non Recur
void postorderNonRecur(Node *root)
{
    stack<pair<Node *, bool>> st;
    Node *current = root;
    bool visited = false;

    while (current != nullptr || !st.empty())
    {
        if (current != nullptr)
        {
            st.push(make_pair(current, visited));
            current = current->left;
            visited = false;
        }
        else
        {
            pair<Node *, bool> top = st.top();
            st.pop();
            current = top.first;
            visited = top.second;

            if (!visited)
            {
                visited = true;
                st.push(make_pair(current, visited));
                current = current->right;
            }
            else
            {
                cout << current->data << " ";
                current = nullptr;
            }
        }
    }
}

int main()
{
    Node *root;
    int choice;
    cout << "1.Recursion\n2.Non-Recursion\n\nEnter the choice: " << endl;
    cin >> choice;
    string postfix = "";
    cout << "Enter the Postfix Expression" << endl;

    cin >> postfix;
    root = CreateExprTree(postfix);

    while (true)
    {

        cout << "\n1.Inorder\n2.Preorder\n3.Postorder\n4.Exit\nEnter the choice: ";
        int n;
        cin >> n;
        switch (choice)
        {
        case 1:
            if (n == 1)
            {
                cout << "Inorder: ";
                Inorder(root);
                cout << endl;
            }
            else if (n == 2)
            {
                cout << "Preorder: ";
                Preorder(root);
                cout << endl;
            }
            else if (n == 3)
            {
                cout << "Postorder: ";
                Postorder(root);
                cout << endl;
            }
            else
            {
                exit(0);
            }

            break;
        case 2:
            if (n == 1)
            {
                cout << "Inorder: ";
                inorderNonRecur(root);
                cout << endl;
            }
            else if (n == 2)
            {
                cout << "Preorder: ";
                preorderNonRecur(root);
                cout << endl;
            }
            else if (n == 3)
            {
                cout << "Postorder: ";
                postorderNonRecur(root);
                cout << endl;
            }
            else
            {
                exit(0);
            }

            break;

        default:
            cout << "invalid";
            break;
        }
    }

    return 0;
}
