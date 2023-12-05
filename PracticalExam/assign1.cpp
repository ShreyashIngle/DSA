#include <iostream>
using namespace std;

void maxHeap(int arr[], int n, int i)
{
    int rootIndex = i;
    int leftIndex = 2 * i + 1;
    int rightIndex = 2 * i + 2;

    if (leftIndex < n && arr[leftIndex] > arr[rootIndex])
    {
        rootIndex = leftIndex;
    }
    if (rightIndex < n && arr[rightIndex] > arr[rootIndex])
    {
        rootIndex = rightIndex;
    }

    if (rootIndex != i)
    {
        swap(arr[rootIndex], arr[i]);
        maxHeap(arr, n, arr[rootIndex]);
    }
}
void minHeap(int arr[], int n, int i)
{
    int rootIndex = i;
    int leftIndex = 2 * i + 1;
    int rightIndex = 2 * i + 2;

    if (leftIndex < n && arr[leftIndex] < arr[rootIndex])
    {
        rootIndex = leftIndex;
    }
    if (rightIndex < n && arr[rightIndex] < arr[rootIndex])
    {
        rootIndex = rightIndex;
    }

    if (rootIndex != i)
    {
        swap(arr[rootIndex], arr[i]);
        maxHeap(arr, n, arr[rootIndex]);
    }
}

void heapSort(int arr[], int n, int choice)
{
    if (choice == 1)
    {
        for (int i = (n / 2 - 1); i >= 0; i--)
        {
            maxHeap(arr, n, i);
        }
        for (int i = n - 1; i >= 0; i--)
        {
            swap(arr[0], arr[i]);
            maxHeap(arr, i, 0);
        }
    }
    else
    {
        for (int i = (n / 2 - 1); i >= 0; i--)
        {
            minHeap(arr, n, i);
        }
        for (int i = n - 1; i >= 0; i--)
        {
            swap(arr[0], arr[i]);
            minHeap(arr, i, 0);
        }
    }
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << endl;

    cout << "Initial Array : ";
    display(arr, n);
    heapSort(arr, n, 1);
    cout << "Sorted Array : ";
    display(arr, n);

    return 0;
}
