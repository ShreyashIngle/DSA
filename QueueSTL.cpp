#include <bits/stdc++.h>
using namespace std;

void display(queue<int> QUEUE){
    queue<int> q= QUEUE;
    while (!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
    
}

int main(int argc, char const *argv[])
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    display(q);

    cout<<"Front :"<<q.front()<<endl;
    cout<<"Rear :"<<q.back()<<endl;
    cout<<"Size :"<<q.size()<<endl;
    return 0;
}
