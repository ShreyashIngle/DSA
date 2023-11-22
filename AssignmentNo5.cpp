#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Recur
struct Node *Insert(struct Node *node, int key)
{
    if (node == NULL)
    {
        return createNode(key);
    }

    if (key < node->data)
    {
        node->left = Insert(node->left, key);
    }

    else if (key > node->data)
    {
        node->right = Insert(node->right, key);
    }

    return node;
}

// Non Recur
struct Node *InsertNonRecur(struct Node *node, int key)
{
    Node *newNode = createNode(key);
    Node *cur = node;
    Node *parent = NULL;

    while (cur != NULL)
    {
        parent = cur;
        if (key < cur->data)
        {
            cur = cur->left;
        }

        else
        {
            cur = cur->right;
        }
    }

    if (parent == NULL)
    {
        return newNode;
    }

    else if (key < parent->data)
    {
        parent->left = newNode;
    }

    else
    {
        parent->right = newNode;
    }
    return node;
}

// Recur
struct Node *Search(struct Node *node, int key)
{
    if (node == NULL || node->data == key)
    {
        return node;
    }

    else if (key < node->data)
    {
        return Search(node->left, key);
    }

    else
    {
        return Search(node->right, key);
    }
}

// Non recur
struct Node *SearchNonRecur(struct Node *node, int key)
{
    Node *temp = node;

    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return temp;
        }

        if (temp->data > key)
        {
            temp = temp->left;
        }
        if (temp->data < key)
        {
            temp = temp->right;
        }
    }
    return temp;
}

Node *minVal(Node *root)
{
    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
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

Node *Delete(Node *root, int k)
{

    if (root == NULL)
        return root;

    if (root->data == k)
    {
        // 0 child;
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // 1 child

        // left
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // right
        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // 2child
        if (root->left != NULL && root->right != NULL)
        {
            int min = minVal(root->right)->data;
            root->data = min;
            root->right = Delete(root->right, min);
            return root;
        }
    }

    else if (root->data > k)
    {
        root->left = Delete(root->left, k);
        return root;
    }
    else
    {
        root->right = Delete(root->right, k);
        return root;
    }
}

int maxDepth(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }

    else
    {
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);
        if (lDepth > rDepth)
        {
            return lDepth + 1;
        }

        else
        {
            return rDepth + 1;
        }
    }
}

void Inorder(struct Node *root)
{
    if (root != NULL)
    {
        Inorder(root->left);
        cout << root->data << " ";
        Inorder(root->right);
    }
}

void Preorder(struct Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        Preorder(root->left);
        Preorder(root->right);
    }
}

void Postorder(struct Node *root)
{
    if (root != NULL)
    {
        Postorder(root->left);
        Postorder(root->right);
        cout << root->data << " ";
    }
}

void mirrorBST(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    std::swap(root->left, root->right);
    mirrorBST(root->left);
    mirrorBST(root->right);
}

int main()
{

    Node *root = NULL;

    int n;
    int choice;
    while (1)
    {
        cout << "\n1.Insert\n2.Delete\n3.Search\n4.Depth\n5.Mirror\n6.Traversals\n7.FindMin\n8.Display Tree\n9.exit\nEnter the choice:";
        // cout << "\n-----MENU-----\n1.Recursion\n2.Non Recursion\nEnter the choice:";
        cin >> choice;
        switch (choice)
        {
        case 1:

            cout << "\n1.Recursion\n2.Non Recursion\nEnter the choice:";
            int i;
            cin >> i;
            if (i == 1)
            {

                cout << "Enter the element to be inserted: ";
                cin >> n;
                root = Insert(root, n);
            }
            else
            {
                cout << "Enter the element to be inserted: ";
                cin >> n;
                root = InsertNonRecur(root, n);
            }
            break;
        case 2:
            cout << "\nEnter element to be deleted : ";
            cin >> n;
            root = Delete(root, n);
            cout << "\nBST after deletion of element is : ";
            Inorder(root);
            break;

        case 3:
            cout << "\n1.Recursion\n2.Non Recursion\nEnter the choice:";

            cin >> i;
            if (i == 1)
            {

                cout << "\nEnter element to be searched : ";
                cin >> n;
                if (Search(root, n) == NULL)
                {
                    cout << n << " Not found";
                }
                else
                {
                    cout << n << " is found" << endl;
                }
            }
            else
            {
                cout << "\nEnter element to be searched : ";
                cin >> n;
                if (SearchNonRecur(root, n) == NULL)
                {
                    cout << n << " Not found";
                }
                else
                {
                    cout << n << " is found" << endl;
                }
            }
            break;
        case 4:
            cout << "\nDepth of tree is: " << maxDepth(root);
            break;

        case 5:
            mirrorBST(root);
            cout << "\nInorder traversal of mirror tree is : ";
            Inorder(root);
            cout << endl;
            LevelOrderTraversal(root);
            break;

        case 6:
            cout << "Inorder:";
            Inorder(root);
            cout << endl;
            cout << "Preorder:";
            Preorder(root);
            cout << endl;
            cout << "Postorder:";
            Postorder(root);
            cout << endl;
            break;

        case 7:
            cout << "\nMinimum element in BST is : " << minVal(root)->data;
            break;

        case 8:
            LevelOrderTraversal(root);
            break;

        case 9:
            exit(0);
            break;

        default:
            cout << "Invalid!!";
            break;
        }
    }

    return 0;
}
