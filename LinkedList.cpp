#include <iostream>
#include <conio.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    void insert(int x);
    void insertAtEnd(int x);
    void print();
};
Node *Head;

void Node::insert(int x)
{
    Node *temp = new Node;
    temp->data = x;
    temp->next = Head;
    Head = temp;
}

void Node::insertAtEnd(int x)
{
    Node *newNode = new Node;
    newNode->data = x;
    newNode->next = NULL;

    if (Head==NULL)
    {
        Head=newNode;
    }
    else{
        Node *temp = Head;
        while (temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        
    }
    
}

void Node::print()
{
    Node *temp = Head;
    while (temp != NULL)
    {

        cout << temp->data << "->";
        temp = temp->next;
    }
}

main(int argc, char const *argv[])
{
    Node list;
    Head = NULL;
    int size, number;

    cout << "Enter the size of the list: ";
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        cout << "Enter the Number: ";
        cin >> number;
        list.insertAtEnd(number);
    }
    list.print();

    getch();
}
