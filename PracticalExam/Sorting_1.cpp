#include <iostream>
#include <string>

using namespace std;

struct Student
{
    int rollno;
    string name;
    float sgpa;
};

void bubblesort(Student arr[], int n)
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

void insertionsort(Student arr[], int n)
{
    for (int i = 1; i < n - 1; i++)
    {
        Student key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j].name > key.name)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
    }
}

int partition(Student arr[], int l, int r)
{
    Student pivot = arr[r];
    int i = l - 1;

    for (int j = l; j < r; j++)
    {
        if (arr[j].sgpa >= pivot.sgpa)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return i + 1;
}
void quicksort(Student arr[], int l, int r)
{
    if (l < r)
    {
        int pi = partition(arr, l, r);
        quicksort(arr, l, pi - 1);
        quicksort(arr, pi + 1, r);
    }
}

void binarysearch(Student arr[], int n, string searchname)
{
    int low = 0;
    int high = n;

    for (int i = 0; i < n; i++)
    {
        int mid = (low + high) / 2;

        if (arr[mid].name == searchname)
        {
            cout << "Roll No: " << arr[mid].rollno << " Name: " << arr[mid].name << " SGPA: " << arr[mid].sgpa << endl;
            break;
        }
        else if (searchname < arr[mid].name)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
}
int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter the no of students: ";
    cin >> n;

    Student students[n];

    int choice;

    while (true)
    {

        cout << "------------------------------------------------------------" << endl
             << endl;
        cout << "Enter your choice with corresponding option number: " << endl;
        cout << "1.Enter Data" << endl;
        cout << "2.Display Data" << endl;
        cout << "3.Sort data according to Roll Number" << endl;
        cout << "4.Sort data according to Name" << endl;
        cout << "5.Display Top ten Toppers" << endl;
        cout << "6.Search name" << endl;
        cout << "7. Exit" << endl;
        cout << "------------------------------------------------------------" << endl
             << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            for (int i = 0; i < n; i++)
            {
                cout << "Enter Roll NO:";
                cin >> students[i].rollno;
                cout << "Enter Name :";
                cin >> students[i].name;
                cout << "Enter SGPA :";
                cin >> students[i].sgpa;
            }
            break;
        case 2:
            for (int i = 0; i < n; i++)
            {
                cout << "Roll No: " << students[i].rollno << " Name: " << students[i].name << " SGPA: " << students[i].sgpa << endl;
            }
            break;
        case 3:
            bubblesort(students, n);

            for (int i = 0; i < n; i++)
            {
                cout << "Roll No: " << students[i].rollno << " Name: " << students[i].name << " SGPA: " << students[i].sgpa << endl;
            }
            break;
        case 4:
            insertionsort(students, n);

            for (int i = 0; i < n; i++)
            {
                cout << "Roll No: " << students[i].rollno << " Name: " << students[i].name << " SGPA: " << students[i].sgpa << endl;
            }
            break;

        case 5:

            quicksort(students, 0, n - 1);

            for (int i = 0; i < n; i++)
            {
                cout << "Roll No: " << students[i].rollno << " Name: " << students[i].name << " SGPA: " << students[i].sgpa << endl;
            }
            break;

        case 6:
        {
            string searchName;
            cout << "Enter name to search: ";
            cin >> searchName;
            cout << "Students with name " << searchName << ":" << endl;
            binarysearch(students, n, searchName);
            break;
        }
        case 7:
            exit(0);
            break;
        }
    }

    return 0;
}
