#include <iostream>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;

    node(int v)
    {
        data = v;
        left = right = nullptr;
    }
};

class BST
{
public:
    node *insertNode(node *root, int v)
    {
        if (root == nullptr)
        {
            return new node(v);
        }

        if (root->data > v)
        {
            cout << "left...\n";
            root->left = insertNode(root->left, v);
        }
        else
        {
            cout << "right..\n";
            root->right = insertNode(root->right, v);
        }

        cout << "Node inserted...\n";
        return root;
    }

    void inorder(node *root)
    {
        if (root == nullptr)
        {
            return;
        }
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    node *searchNode(node *root, int key)
    {
        if (root == NULL)
        {
            return nullptr;
        }

        if (root->data == key)
        {
            cout << "root found\n";
            return root;
        }
        else if (root->data > key)
        {
            return searchNode(root->left, key);
        }
        else
        {
            return searchNode(root->right, key);
        }
    }

    node *deleteNode(node *root, int d)
    {

        if (root->data == d)
        {
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                return NULL;
            }
            else if (root->left != NULL && root->right == NULL)
            {
                node *temp = root->left;
                delete root;
                return temp;
            }
            else if (root->left == NULL && root->right != NULL)
            {
                node *temp = root->right;
                delete root;
                return temp;
            }
        }
        else if (root->data > d)
        {
            root->left = deleteNode(root->left, d);
        }
        else
        {
            root->right = deleteNode(root->right, d);
        }
        return root;
    }

    node *leafNode(node *root)
    {
        if (root == NULL)
        {
            return NULL;
        }

        if (root->left == NULL && root->right == NULL)
        {
            cout << root->data << " ";
        }
        leafNode(root->left);
        leafNode(root->right);
    }

    int depth(node *root)
    {
        node *temp = root;
        if (temp == NULL)
        {
            return 0;
        }
        else
        {
            int ldepth = depth(temp->left);
            int rdepth = depth(temp->right);

            if (ldepth > rdepth)
            {
                return (ldepth + 1);
            }
            else
            {
                return (rdepth + 1);
            }
        }
    }

    void parentandChild(node *root)
    {
        if (root == NULL)
        {
            return;
        }
        cout << "Parent:" << root->data;

        if (root->left != NULL)
        {
            cout << "Left child:" << root->left->data;
        }

        if (root->right != NULL)
        {
            cout << "Right child:" << root->right->data;
        }
        cout << endl;
        parentandChild(root->left);
        parentandChild(root->right);
    }
};
int main()
{
    BST s;
    node *root = NULL;
    int choice, data, key;

    while (true)
    {
        int choice;
        cout << "\n\n------ Menu ------" << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Inorder Traversal" << endl;
        cout << "3. Delete Node (by key)" << endl;
        cout << "4. Find Leaf Nodes" << endl;
        cout << "5. Search for a Key" << endl;
        cout << "6. Get Depth of Tree" << endl;
        cout << "7. Print Parent and Child Relationships" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter data to insert: ";
            cin >> data;
            root = s.insertNode(root, data);
            break;
        case 2:
            s.inorder(root);
            break;
        case 3:
            cout << "Enter key to delete: ";
            cin >> key;
            s.deleteNode(root, key);
            break;
        case 4:
            s.leafNode(root);
            break;
        case 5:
            cout << "Enter key to search: ";
            cin >> key;
            s.searchNode(root, key);
            break;
        case 6:
            cout << "Depth of tree: " << s.depth(root) << endl;
            break;
        case 7:
            s.parentandChild(root);
            break;
        case 8:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }

        if (choice == 8)
        {
            break;
        }
    }

    return 0;
}
