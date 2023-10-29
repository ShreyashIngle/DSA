#include <bits/stdc++.h>
using namespace std;

struct Node
{
public:
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

//Using Recursion
Node *createNode(Node *root)
{
    int data;
    cout << "Enter the data:" << endl;
    cin >> data;

    root = new Node(data);
    if (data == -1)
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
//using Nonrecursion
// Node bulidFromLevelOrderTraveral(Node* &root)
// {
//     queue<Node *> q;
//     cout << "Enter data for root: ";
//     int data;
//     cin >> data;

//     root = new Node(data);
//     q.push(root);

//     while (!q.empty())
//     {
//         Node *temp = q.front();
//         q.pop();

//         cout << "Enter Left data for: " << temp->data << endl;
//         int leftData;
//         cin >> leftData;

//         if (leftData != -1)
//         {
//             temp->left = new Node(leftData);
//             q.push(temp->left);
//         }
//         cout << "Enter Right data for: " << temp->data << endl;
//         int rightData;
//         cin >> rightData;

//         if (rightData != -1)
//         {
//             temp->right = new Node(rightData);
//             q.push(temp->right);
//         }
//     }
// }

int main(int argc, char const *argv[])
{
    Node *root = NULL;
    // 1 3 7 -1 -1  11 -1 -1 5 17 -1 -1 -1

    // bulidFromLevelOrderTraveral(root);
    // LevelOrderTraversal(root);
    root = createNode(root);
    LevelOrderTraversal(root);

    cout << "Inorder: ";
    Inorder(root);
    cout << endl;
    cout << "Preorder: ";
    Preorder(root);
    cout << endl;
    cout << "Postorder: ";
    Postorder(root);
    cout << endl;

    return 0;
}
