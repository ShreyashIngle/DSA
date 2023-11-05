#include <bits/stdc++.h>
using namespace std;

struct Node
{
public:
    char data;
    struct Node *left;
    struct Node *right;

    Node(char val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Using Recursion
Node *createNode(Node *root)
{
    char data;
    cout << "Enter the data:" << endl;
    cin >> data;

    root = new Node(data);
    if (data == ',')
    {
        return NULL;
    }

    cout << "Enter the data to insert in left of " << data << endl;
    root->left = createNode(root->left);
    cout << "Enter the data to insert in right of " << data << endl;
    root->right = createNode(root->right);

    return root;
}

void LevelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void Inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}
void Preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}
void Postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << " ";
}
// using Nonrecursion
Node bulidFromLevelOrderTraveral(Node *&root)
{
    queue<Node *> q;
    cout << "Enter data for root: ";
    char data;
    cin >> data;

    root = new Node(data);
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        cout << "Enter Left data for: " << temp->data << endl;
        char leftData;
        cin >> leftData;

        if (leftData != -1)
        {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }
        cout << "Enter Right data for: " << temp->data << endl;
        char rightData;
        cin >> rightData;

        if (rightData != -1)
        {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}

int main(int argc, char const *argv[])
{
    Node *root = NULL;
    // 1 3 7 -1 -1  11 -1 -1 5 17 -1 -1 -1

    cout << "\n1.Recursive\n2.Non Recursive\n\nEnter the choice: ";
    int rec;
    cin >> rec;
    if (rec == 1)
    {
        root = createNode(root);
        LevelOrderTraversal(root);
    }
    else
    {
        bulidFromLevelOrderTraveral(root);
    }

    int choice;
    while (true)
    {
        cout << endl
             << "1.Inorder\n2.Preorder\n3.Postorder\n4.Exit\n\nEnter the choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Inorder: ";
            Inorder(root);
            cout << endl;
            break;
        case 2:
            cout << "Preorder: ";
            Preorder(root);
            cout << endl;
            break;
        case 3:
            cout << "Postorder: ";
            Postorder(root);
            cout << endl;
            break;
        case 4:
            exit(0);
            break;

        default:
            break;
        }
    }
    return 0;
}