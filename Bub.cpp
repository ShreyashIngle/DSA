#include <iostream>

using namespace std;


void Bubble(){
    int n ;
    cout<<"Enter the no you want to add in array:";
    cin>>n;
    int arr[n];


    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
     int counter=1;
    while (counter <n)
    {
        for (int i = 0; i < n - counter; i++)
        {
            if (arr[i]>arr[i+1])
            {
                int temp = arr[i];
                arr[i]= arr[i+1];
                arr[i+1]= temp;
            }
            
        }
        counter++;
    }
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<' ';
    }
    
}
int main(int argc, char const *argv[])
{
    Bubble();
    return 0;
}
