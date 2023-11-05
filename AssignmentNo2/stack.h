#ifndef STACK_H_
#define STACH_H_
#include <iostream>
using namespace std;

template<class T>
class stack;

template<class T>
class node{
	public:
	T data;
	node <T>*next;
	node(){
		data=0;
		next=NULL;
	}
	friend class stack<T>;
};

template<class T>
class stack{
		
	public :
	node<T> *top=NULL;
       	void push(T k);
       	void pop();
       	void display();
       	bool isempty();
       	T isTop();
       	stack();
      	
};
 #endif
