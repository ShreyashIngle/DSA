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

int main()
{

    Node *root = NULL;
    root = InsertNonRecur(root, 50);
    root = InsertNonRecur(root, 20);
    root = InsertNonRecur(root, 70);
    root = InsertNonRecur(root, 10);
    root = InsertNonRecur(root, 30);
    root = InsertNonRecur(root, 90);
    root = InsertNonRecur(root, 110);

    LevelOrderTraversal(root);

    cout << "Inorder:";
    Inorder(root);
    cout << endl;

    root = Delete(root, 10);
    LevelOrderTraversal(root);

    // root = Delete(root, 20);
    // cout << "Inorder:";
    // Inorder(root);
    // cout << endl;

    // cout << maxDepth(root);
    /*cout<<endl;
    cout<<"Preorder:";
    Preorder(root);
    cout<<endl;

    cout<<"Postorder:";
    Postorder(root);
    cout<<endl;*/

    int key = 10;

    if (SearchNonRecur(root, key) == NULL)
    {
        cout << key << " Not found";
    }
    else
    {
        cout << key << " is found" << endl;
    }

    int k = 13;

    if (Search(root, k) == NULL)
    {
        cout << k << " Not found";
    }
    else
    {
        cout << k << " is found" << endl;
    }

    cout << endl
         << minVal(root)->data;
    return 0;
}
