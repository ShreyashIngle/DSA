#include <bits/stdc++.h>

using namespace std;

struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* createNode(int data){
	Node* newNode = new Node;
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

struct Node* Insert(struct Node* node,int key)
{
	if(node==NULL){
		return createNode(key);
	}
	
	
	if(key<node->data){
		node->left =  Insert(node->left,key);
	}
	
	else if(key>node->data){
		node->right =  Insert(node->right,key);
	}
	
	return node; 

}

struct Node* Search(struct Node* node,int key)
{
	if(node==NULL||node->data==key){
		return node;
	}
	
	else if(key<node->data){
		return Search(node->left,key);
	}
	
	else{
		return Search(node->right,key);
	}
}


Node* Delete(Node* root, int k)
{

    if (root == NULL)
        return root;
 

    if (root->data > k) {
        root->left = Delete(root->left, k);
        return root;
    }
    else if (root->data < k) {
        root->right = Delete(root->right, k);
        return root;
    }
 
   
    if (root->left == NULL) {
        Node* temp = root->right;
        delete root;
        return temp;
    }
    else if (root->right == NULL) {
        Node* temp = root->left;
        delete root;
        return temp;
    }
 

    else {
 
        Node* succParent = root;
 
      
        Node* succ = root->right;
        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }
 
     
        if (succParent != root)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;
 
 
        root->data = succ->data;
 
   
        delete succ;
        return root;
    }
}

int maxDepth(Node* node){
	if(node == NULL){
		return 0;
	}
	
	else{
		int lDepth = maxDepth(node->left);
		int rDepth= maxDepth(node->right);
		if(lDepth>rDepth){
		 return lDepth+1;	
		}
		
		else{
		  return rDepth+1;
		}
	}
}
 


void Inorder(struct Node* root){
	if(root!=NULL){
		Inorder(root->left);
		cout<<root->data<<" ";
		Inorder(root->right);
	}
}

void Preorder(struct Node* root){
	if(root!=NULL){
		cout<<root->data<<" ";
		Preorder(root->left);
		Preorder(root->right);
	}
}

void Postorder(struct Node* root){
	if(root!=NULL){
		Postorder(root->left);
		Postorder(root->right);
		cout<<root->data<<" ";
	}
}



int main(){
	
	Node* root =NULL;
	root = Insert(root,50);
	root = Insert(root,40);
	root =Insert(root,30);
	root = Insert(root,20);
	root = Insert(root,10);
	
	cout<<"Inorder:";
	Inorder(root);
	cout<<endl;
	
	root = Delete(root,10);
	cout<<"Inorder:";
	Inorder(root);
	cout<<endl;
	
	root = Delete(root,20);
	cout<<"Inorder:";
	Inorder(root);
	cout<<endl;
	
	cout<<maxDepth(root);
	/*cout<<endl;
	cout<<"Preorder:";
	Preorder(root);
	cout<<endl;
	
	cout<<"Postorder:";
	Postorder(root);
	cout<<endl;*/
	
	
	int key = 10;
	
	if(Search(root,key)==NULL){
		cout<<"Not found";
	}
	else{
		cout<<key<<" is found"<<endl;
	}
	
	
	

return 0;
}
