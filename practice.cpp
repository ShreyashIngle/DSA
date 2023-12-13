#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int v)
    {
        data = v;
        left = right = nullptr;
    }
};

class BST
{
public:
    Node *insertNode(Node *root, int v)
    {
        if (root->data == nullptr)
        {
            return new Node(v);
        }
        else if (root->data > v)
        {
            cout << "left..";
            root->left = insertNode(root->left, v);
        }
        else
        {
            cout << "\nright...";
            root->right = insertNode(root->right, v);
        }
        cout << "Node Inserted";
        return root;
    }

    Node *searchNode(Node *root, int key)
    {
        if (root->data == nullptr)
        {
            return;
        }
        else if (root->data == key)
        {
            cout << " data found\n";
            return root;
        }
        else if (root->data > key)
        {
            return searchNode(root->left, v);
        }
        else
        {
            return searchNode(root->right, v);
        }
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

    Node *deleteNode(Node *root, int d)
    {
        if (root->data == d)
        {
            if (root->data == nullptr && root->data == nullptr)
            {
                delete root;
                return nullptr;
            }
            else if (root->data != nullptr && root->data == nullptr)
            {
                Node *temp = root->left;
                delete root;
                return temp;
            }
            else if (root->data == nullptr && root->data != nullptr)
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }
        }
        else
        {
            if (root->data > d)
            {
                root->left = deleteNode(root->left, d);
            }
            else
            {
                root->right = deleteNode(root->right, d);
            }
        }
        return root;
    }

    Node* leafNode(Node* root){
        if(root==nullptr){
            return nullptr;

        }
        if(root->left == nullptr &&root->right==right){
            cout<<root->data<<" ";
        }
        leafNode(root->left);
        leafNode(root->right);
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
