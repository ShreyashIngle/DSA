
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student
{
    int roll_number;
    string name;
    string division;
    string address;
};

void create_file()
{
    ofstream file("C:\\Users\\Tejas Ingle\\OneDrive\\Desktop\\PICT Study\\DSA\\AssignmentNo10\\students.txt");
    if (!file)
    {
        cerr << "Error creating file." << endl;
        return;
    }
    cout << "File created successfully." << endl;
    file.close();
}

void add_student()
{
    Student student;
    cout << "Enter roll number: ";
    cin >> student.roll_number;
    cin.ignore();

    cout << "Enter name: ";
    getline(cin, student.name);

    cout << "Enter division: ";
    getline(cin, student.division);

    cout << "Enter address: ";
    getline(cin, student.address);

    ofstream file("students.txt", ios::app);
    if (!file)
    {
        cerr << "Error opening file." << endl;
        return;
    }
    file << student.roll_number << " " << student.name << " " << student.division << " " << student.address << endl;
    file.close();
    cout << "Student added successfully." << endl;
}

void display_student()
{
    int roll_number;
    cout << "Enter roll number to search: ";
    cin >> roll_number;

    ifstream file("students.txt");
    if (!file)
    {
        cerr << "Error opening file." << endl;
        return;
    }

    Student student;
    bool found = false;
    while (file >> student.roll_number >> student.name >> student.division >> student.address)
    {
        if (student.roll_number == roll_number)
        {
            found = true;
            break;
        }
    }

    file.close();

    if (found)
    {
        cout << "Roll number: " << student.roll_number << endl;
        cout << "Name: " << student.name << endl;
        cout << "Division: " << student.division << endl;
        cout << "Address: " << student.address << endl;
    }
    else
    {
        cout << "Student not found." << endl;
    }
}

void delete_student()
{
    int roll_number;
    cout << "Enter roll number of student to delete: ";
    cin >> roll_number;

    ifstream original_file("students.txt");
    if (!original_file)
    {
        cerr << "Error opening file." << endl;
        return;
    }

    ofstream temp_file("temp.txt");
    if (!temp_file)
    {
        cerr << "Error opening file." << endl;
        original_file.close();
        return;
    }

    Student student;
    bool deleted = false;
    while (original_file >> student.roll_number >> student.name >> student.division >> student.address)
    {
        if (student.roll_number != roll_number)
        {
            temp_file << student.roll_number << " " << student.name << " " << student.division << " " << student.address << endl;
        }
        else
        {
            deleted = true;
        }
    }

    original_file.close();
    temp_file.close();

    if (deleted)
    {
        remove("students.txt");
        rename("temp.txt", "students.txt");
        cout << "Student deleted successfully." << endl;
    }
    else
    {
        cout << "Student not found." << endl;
    }
}

int main()
{
    int choice;
    do
    {
        cout << "\n1. Create file\n2. Add student\n3. Display student\n4. Delete student\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            create_file();
            break;
        case 2:
            add_student();
            break;
        case 3:
            display_student();
            break;
        case 4:
            delete_student();
            break;
        case 5:
            break; // Exit
        default:
            cout << "Invalid choice." << endl;
        }
    } while (choice != 5); 
    return 0;
}
