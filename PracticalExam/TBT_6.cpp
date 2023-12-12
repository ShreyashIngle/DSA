#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    int left_th, right_th;

    Node(int x)
    {
        data = x;
        left = right = NULL;
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

        cout << "Enter data or -1 to stop: ";
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
        else if (child == 1)
        {
            newNode->right = parent->right;
            newNode->left = parent;
            parent->right = newNode;
            parent->right_th = 1;
        }

        cout << "Enter left of " << value << ": ";
        createRecursive(newNode, 0);

        cout << "Enter right of " << value << ": ";
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

    void preorder()
    {
        cout << "Preorder traversal:\n";
        Node *current = root->left;

        while (current != root)
        {
            cout << current->data << " ";

            while (current->left_th == 1)
            {
                current = current->left;
                cout << current->data << " ";
            }

            while (current->right_th == 0 || current->right == root)
            {
                current = current->right;
                if (current == root)
                {
                    return;
                }
            }

            current = current->right;
        }
    }
};

int main()
{
    TBT tree;
    int choice;

    while (true)
    {
        cout << "\n1: Create TBT\n2: Inorder Traversal\n3: Preorder Traversal\n4: Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            tree.create();
            break;
        case 2:
            tree.inorder();
            break;
        case 3:
            tree.preorder();
            break;
        case 4:
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
