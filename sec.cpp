#include <iostream>

using namespace std;

void sec()
{
    int n;
    cout << "Enter the no you want to add in array:";
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            /* code */
            if (arr[j] < arr[i])
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<' ';
    }
    
}

int main(int argc, char const *argv[])
{
    sec();
    return 0;
}
