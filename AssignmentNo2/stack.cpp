#include <iostream>
#include "stack.h"
using namespace std;

template<class T>
stack<T>::stack(){
	top=NULL;
}

template<class T>
bool stack<T>::isempty(){
	if(top==NULL){
		return 1;
	}
	else{
		return 0;
	}
}
template<class T>
void stack<T>::push(T k){
	node<T> *New;
     	New=new node<T>;
    	New->data=k;
     	New->next=top;
     	top=New;
}

template<class T>
void stack<T>::pop(){
	if(top!=NULL){
          node<T> *temp;
          temp=top;
          top=top->next;
          delete temp;
      }
      else
            cout<<"Stack empty";
}

template<class T>
T stack<T>::isTop(){
	return top->data;
}

template<class T>
void stack<T>::display(){
	node<T> *temp=top;
     	while(temp!=NULL)
     	{
       	cout<<temp->data<<" ";
       	temp=temp->next;
     	}
}








//

