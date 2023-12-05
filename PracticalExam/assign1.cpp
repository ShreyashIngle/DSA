#include <iostream>
using namespace std;

struct Student
{
    int rollno;
    string name;
    float sgpa;
};

void BubbleSort(Student arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j].rollno > arr[j + 1].rollno)
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    Student s[n];
    s[0].rollno = 5;
    s[1].rollno = 4;
    s[2].rollno = 3;
    s[3].rollno = 2;
    s[4].rollno = 1;

    BubbleSort(s, n);
    for (int i = 0; i < n; i++)
    {
        cout << s[i].rollno << " ";
    }

    return 0;
}
