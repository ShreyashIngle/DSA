#include <bits/stdc++.h>
using namespace std;

struct Node
{
public:
    int data;
    Node *left, *right;
    int left_th, right_th;

    Node(int x)
    {
        data = x;
        left = right = nullptr;
        left_th = right_th = 0;
    }
};

class TBT
{
public:
    Node *root;
    TBT()
    {
        root = new Node(-1);
        root->left = root->right = root;
    }

    void create()
    {
        createRecursive(root, 0);
    }

    void createRecursive(Node *parent, int child)
    {
        int value;
        cout << "\nEnter the value or -1 to exit :";
        cin >> value;

        if (value == -1)
        {
            return;
        }

        Node *newNode = new Node(value);

        if (child == 0)
        {
            newNode->left = parent->left;
            newNode->right = parent;
            parent->left = newNode;
            parent->left_th = 1;
        }
        else
        {
            newNode->right = parent->right;
            newNode->left = parent;
            parent->right = newNode;
            parent->right_th = 1;
        }

        cout << "\nEnter the left value of " << value << ":";
        createRecursive(newNode, 0);

        cout << "\nEnter the right value of " << value << ":";
        createRecursive(newNode, 1);
    }
    void inorder()
    {
        cout << "\nInorder traversal:\n";
        Node *current = root->left;

        while (current != root)
        {
            while (current->left_th == 1)
            {
                current = current->left;
                cout << current->data << " ";
            }

            cout << current->data << " ";

            while (current->right_th == 0 || current->right == root)
            {
                current = current->right;
                if (current == root)
                {
                    return;
                }
                cout << current->data << " ";
            }

            current = current->right;
        }
    }
};

int
main(int argc, char const *argv[])
{
    TBT tree;
    int choice;
    while (true)
    {
        cout << "\n1.Create Tree\n2.Inorder\nPreorder\nEnter the choice:";
        cin >> choice;

        switch (choice)
        {
        case 1:
            tree.create();
            break;

        case 2:
            tree.inorder();
            break;

        default:
            break;
        }
    }

    return 0;
}
