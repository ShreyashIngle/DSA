#include <iostream>
#include <string>
using namespace std;

// Structure to store student information
struct Student
{
    int rollNo;
    string name;
    float sgpa;
};

// Function to perform Bubble Sort
void bubbleSort(Student arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j].rollNo > arr[j + 1].rollNo)
            {

                // int temp = arr[j];
                // arr[j] = arr[j+1];
                // arr[j+1] = temp;
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
    
// Function to perform Insertion Sort
void insertionSort(Student arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        Student key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].name > key.name)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Function to perform Quick Sort
int partition(Student arr[], int low, int high)
{
    Student pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j].sgpa >= pivot.sgpa)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(Student arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to perform Binary Search (Non-recursive)
void binarySearch(Student arr[], int n, string searchName)
{
    bool found = false;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].name == searchName)
        {
            found = true;
            cout << "Roll No: " << arr[i].rollNo << ", Name: " << arr[i].name << ", SGPA: " << arr[i].sgpa << endl;
        }
    }
    if (!found)
    {
        cout << "Student with name " << searchName << " not found." << endl;
    }
}

int main()
{
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    Student students[n];

    // char choice_loop = 'n';
    int choice;

    while (true)
    {

        cout << "------------------------------------------------------------" << endl
             << endl;
        cout << "Enter your choice with corresponding option number: " << endl;
        cout << "1.Enter Data" << endl;
        cout << "2.Display Data" << endl;
        cout << "3.Search SGPA" << endl;
        cout << "4.Sort data according to Roll Number" << endl;
        cout << "5.Sort data according to Name" << endl;
        cout << "6.Search name" << endl;
        cout << "7.Display Top ten Toppers" << endl;
        cout << "8. Exit" << endl;
        cout << "------------------------------------------------------------" << endl
             << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            for (int i = 0; i < n; i++)
            {
                cout << "Enter details for student " << i + 1 << ":" << endl;
                cout << "Roll No: ";
                cin >> students[i].rollNo;
                cout << "Name: ";
                cin >> students[i].name;
                cout << "SGPA: ";
                cin >> students[i].sgpa;
            }
            break;
        case 2:
        {
            cout << "------------------------------------------------------------" << endl;
            for (int i = 0; i < n; i++)
            {

                cout << "Name: " << students[i].name << "\t";
                cout << "Roll No.: " << students[i].rollNo << "\t";
                cout << "SGPA: " << students[i].sgpa << endl;
            }
            cout << "------------------------------------------------------------" << endl;
        }
        break;

        case 3:
        {
            float searchSGPA;
            cout << "Enter SGPA to search: ";
            cin >> searchSGPA;
            cout << "Students with SGPA " << searchSGPA << ":" << endl;
            bool foundSGPA = false;
            for (int i = 0; i < n; i++)
            {
                if (students[i].sgpa == searchSGPA)
                {
                    foundSGPA = true;
                    cout << "Roll No: " << students[i].rollNo << ", Name: " << students[i].name << ", SGPA: " << students[i].sgpa << endl;
                }
            }
            if (!foundSGPA)
            {
                cout << "No students found with SGPA " << searchSGPA << endl;
            }
        }
        break;

        case 4:
        {
            bubbleSort(students, n);

            cout << "Sorted by Roll No (Ascending Order):" << endl;
            for (int i = 0; i < n; i++)
            {
                cout << "Roll No: " << students[i].rollNo << ", Name: " << students[i].name << ", SGPA: " << students[i].sgpa << endl;
            }
        }
        break;

        case 5:
        {
            insertionSort(students, n);

            cout << "Sorted Alphabetically:" << endl;
            for (int i = 0; i < n; i++)
            {
                cout << "Roll No: " << students[i].rollNo << ", Name: " << students[i].name << ", SGPA: " << students[i].sgpa << endl;
            }
        }
        break;

        case 6:
        {
            string searchName;
            cout << "Enter name to search: ";
            cin >> searchName;
            cout << "Students with name " << searchName << ":" << endl;
            binarySearch(students, n, searchName);
        }
        break;

        case 7:
        {
            quickSort(students, 0, n - 1);

            cout << "Top 10 Toppers:" << endl;
            for (int i = 0; i < min(10, n); i++)
            {
                cout << "Roll No: " << students[i].rollNo << ", Name: " << students[i].name << ", SGPA: " << students[i].sgpa << endl;
            }
        }
        break;

        case 8:
            // choice_loop = 'y';
            exit(0);
            break;
        default:
            cout << "Invalid Input!" << endl;
            break;
        }
    }

    return 0;
}