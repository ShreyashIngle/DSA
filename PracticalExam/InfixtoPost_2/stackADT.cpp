#include<iostream>
using namespace std;

template <typename T> 
struct node
{
    /* data */
    T data;
    node* next;
};

template <typename T> 
class stackADT{
    public:
    node<T>* head;

    stackADT(){
        head=nullptr;
    }

    bool isempty(){
        if(head==NULL){
            return true;
        }
        else{
            return false;
        }
    }

    void push(int v){
        node<T>* temp=new node<T>();
        temp->data=v;
        temp->next=head;
        head=temp;
    }

    char pop(){
        char x;
        node<T>* temp=head;
        x=head->data;
        head=head->next;
        delete temp;
        return x;

    }

    char peek(){
        if(isempty()){
            return '\0';
        }
        return head->data;
    }

    void display(){
        node<T>* current=head;
        while(current!=NULL){
            cout<<current->data<<" ";
            current=current->next;
        }
    }
};
