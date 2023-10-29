#include <iostream>

using namespace std;


int Bin(){
    int i;
    int low,high,mid;
    int x;
    int n;

    cout<<"how many no you want to add:";
    cin>>n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];

    }
    
    cout<<"enter the element you want to search:";
    cin>>x;
    while (low<high)
    {
        mid=(low+high)/2;

        if (x==arr[mid])
        {
            
            return arr[mid];
        }
        else if (x>arr[mid] )
        {
           low = mid+1; 
        }
        else{
            high = mid-1;
        }
    }
    
}
int main(int argc, char const *argv[])
{
    Bin();
    return 0;
}
