#include <bits/stdc++.h>
using namespace std;

struct Student
{
    int roll_no;
    string name;
    string address;
};

void create_file()
{
    ofstream file("C:\\Users\\Tejas Ingle\\OneDrive\\Desktop\\PICT Study\\DSA\\PracticalExam\\students.txt");
    if (!file)
    {
        cout << "Error!!";
        return;
    }
    else
    {
        cout << "File created sucessfully!!";
        file.close();
    }
}

void add_student()
{
    Student student;
    cout << endl
         << "Roll:";
    cin >> student.roll_no;
    cin.ignore();

    cout << "Name:";
    getline(cin, student.name);

    cout << "Address:";
    getline(cin, student.address);

    ofstream file("students.txt", ios::app);
    if (!file)
    {
        cout << "error";
        return;
    }

    file << student.roll_no << " " << student.name << " " << student.address << endl;
    file.close();
    cout << "Student added successfully";
}

void display()
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

    while (file >> student.roll_no >> student.name >> student.address)
    {
        if (student.roll_no == roll_number)
        {
            found = true;
            break;
        }
    }

    file.close();
    if (found)
    {
        cout << "Roll number: " << student.roll_no << endl;
        cout << "Name: " << student.name << endl;

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
    cout << "Enter roll number to search: ";
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
        return;
    }
    Student student;
    bool deleted = false;

    while (original_file >> student.roll_no >> student.name >> student.address)
    {
        if (student.roll_no != roll_number)
        {
            temp_file << student.roll_no << " " << student.name << " " << student.address << endl;
        }
        else
        {
            deleted = true;
        }

        original_file.close();
        temp_file.close();

        if (deleted)
        {
            remove("students.txt");
            rename("temp.txt", "students.txt");
            cout << "Deleted successfully";
        }
    }
}
int main(int argc, char const *argv[])
{
    create_file();
    add_student();
    display();
    delete_student();
    return 0;
}
