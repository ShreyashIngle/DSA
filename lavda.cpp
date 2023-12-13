#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int v){
        data = v;
        left = nullptr;
        right =nullptr;
    }
};

class BST
{
public:
    Node *InsertNode(Node *root, int v)
    {
        if (root == nullptr)
        {
            return new Node(v);
        }
        else if (root->data > v)
        {
            root->left = InsertNode(root->left, v);
        }
        else
        {
            root->right = InsertNode(root->right, v);
        }
        return root;
    }
    Node *searchNode(Node *root, int key)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        else if(root->data ==key){
            cout<<"root found";
            return root;
        }
        else if (root->data > key)
        {
            root->left = searchNode(root->left, key);
        }
        else
        {
            root->right = searchNode(root->right, key);
        }
        
    }

    void Inorder(Node* root){
        if(root!=nullptr){
            Inorder(root->left);
            cout<<root->data<<" ";
            Inorder(root->right);
        }
    }

    Node* deleteNode(Node* root,int d){
        if(root->data ==d){
            if(root->left==nullptr&&root->right==nullptr){
                delete root;
                return nullptr;
            }
            else if(root->left!=nullptr&&root->right==nullptr){
                Node* temp = root->left;
                delete root;
                return temp;
            }
            else if(root->left==nullptr&&root->right!=nullptr){
                Node* temp = root->right;
                delete root;
                return temp;
            }
        }
        else{
            if(root->data>d){
                root->left = deleteNode(root->left,d);
            }
            else{
                 root->right = deleteNode(root->right,d);
            }
        }
        return root;
    }

    Node* leafNode(Node*root){
        if(root==nullptr){
            return nullptr;
        }
        else if(root->left==nullptr&&root->right==nullptr){
            cout<<root->data<<" ";
        }
        leafNode(root->left);
        leafNode(root->right);
    }

    int depth(Node* root){
        Node* temp = root;

        if(temp==nullptr){
            return 0;
        }

        else{
            int ldepth = depth(temp->left);
            int rdepth = depth(temp->right);

            if(ldepth>rdepth){
                return (ldepth+1);
            }
            else{
                   return (rdepth+1);
            }
        }
    }

    void parentandChild(Node* root){
        if(root==nullptr){
            return;
        }
        cout<<"Parent"<<root->data;
        if(root->left!=nullptr){
            cout<<"\nLeft.."<<root->left->data;
        }
         if(root->right!=nullptr){
            cout<<"\right.."<<root->right->data;
        }
        cout<<endl;
        parentandChild(root->left);
        parentandChild(root->right);
    }

};
int main()
{
    BST s;
    Node *root = NULL;
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
            root = s.InsertNode(root, data);
            break;
        case 2:
            s.Inorder(root);
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


