#include <iostream>

using namespace  std ;

int main(int argc, char const *argv[])
{
    int arr[10],i,n,m,index;
    cout <<"Enter how many numbers you want to add in the array:";
    cin >>n;
    for (int  i = 0; i <n; i++)
    {
        cout <<"Enter the number: "<<endl;
        cin>>arr[i];
    }

    cout<<"Enter the number you want to search:"<<endl;
    cin>>m;
    
    for (int j  = 0; j < 10; j++)
    {
        if (arr[j]==m)
        {
           index=j;
           break;
        }
        
    }
    
    cout <<"Found the number at the position of : "<<index<<endl;

    


    return 0;
}
