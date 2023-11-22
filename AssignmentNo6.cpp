#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    bool leftThread, rightThread;

    Node() {
        left = nullptr;
        right = nullptr;
        leftThread = false;
        rightThread = false;
    }

    Node(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
        leftThread = false;
        rightThread = false;
    }
};

class InorderThreadedBinaryTree {
private:
    Node *root;
    Node *lastNodeVisited;

public:
    InorderThreadedBinaryTree() {
        root = nullptr;
        lastNodeVisited = nullptr;
    }

    void insert(int data) {
        Node *newNode = new Node(data);

        if (root == nullptr) {
            root = newNode;
        } else {
            Node *current = root;
            Node *parent = nullptr;

            while (current != nullptr) {
                parent = current;

                if (data < current->data) {
                    if (current->leftThread) {
                        current->left = newNode;
                        current->leftThread = true;
                        break;
                    } else {
                        current->left = newNode;
                        current->leftThread = false;
                        break;
                    }
                } else {
                    if (current->rightThread) {
                        current->right = newNode;
                        current->rightThread = true;
                        break;
                    } else {
                        current->right = newNode;
                        current->rightThread = false;
                        break;
                    }
                }
            }

            if (current == nullptr) {
                delete newNode; // Delete newNode if not inserted
            }
        }
    }

    void inorderThread() {
        if (root == nullptr) {
            return;
        }

        Node *current = root;
        Node *lastNodeVisited = nullptr;

        while (current != nullptr) {
            if (current->leftThread) {
                current = current->leftThread;
            } else {
                current->leftThread = lastNodeVisited;
                if (lastNodeVisited != nullptr) {
                    lastNodeVisited->rightThread = current;
                }
                lastNodeVisited = current;

                current = current->left;
            }
        }
    }

    void inorderTraverse() {
        if (root == nullptr) {
            return;
        }

        Node *current = root;
        while (current != nullptr) {
            if (current->leftThread) {
                current = current->leftThread;
            } else {
                visit(current); // Calling the 'visit' function outside the class

                current = current->right;
            }
        }
    }

    void preorderTraverse() {
        if (root == nullptr) {
            return;
        }

        Node *current = root;
        while (current != nullptr) {
            visit(current);  // Calling the 'visit' function outside the class

            if (current->leftThread) {
                current = current->right;
            } else {
                while (current->leftThread != nullptr) {
                    current = current->leftThread;
                }

                current = current->left;
            }
        }
    }

    void insertMultiple(int data[], int length) {
        for (int i = 0; i < length; i++) {
            insert(data[i]);
        }
    }
};

void visit(Node *node) {
    std::cout << node->data << " ";
}

int main() {
    InorderThreadedBinaryTree tree;

    int data[] = {5, 3, 8, 2, 4, 7, 9};
    int length = sizeof(data) / sizeof(data[0]);

    tree.insertMultiple(data, length);

    tree.inorderThread();
    tree.inorderTraverse();
    std::cout << std::endl;
    tree.preorderTraverse();

    return 0;
}
