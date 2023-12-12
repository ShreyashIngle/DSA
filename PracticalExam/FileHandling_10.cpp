#include <bits/stdc++.h>
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
    ofstream file("C:\\Users\\Tejas Ingle\\OneDrive\\Desktop\\PICT Study\\DSA\\PracticalExam\\students.txt");
    if (!file)
    {
        cout << "Error openinig file.." << endl;
        return;
    }
    else
    {
        cout << "File created successfully.." << endl;
        file.close();
    }
}

void add_student()
{
    Student student;
    cout << "\nEnter the roll no:";
    cin >> student.roll_number;
    cin.ignore();
    cout << "\nEnter the name:";
    getline(cin, student.name);
    cout << "\nEnter the division:";
    getline(cin, student.division);
    cout << "\nEnter the address:";
    getline(cin, student.address);

    ofstream file("students.txt", ios::app);
    if (!file)
    {
        cout << "Error opeing file..";
        return;
    }
    file << student.roll_number << " " << student.name << " " << student.division << " " << student.address << endl;
    cout << "Student added success fully..." << endl;
    file.close();
}

void display()
{
    int roll_number;
    cout << "Enter the roll number: ";
    cin >> roll_number;

    ifstream file("students.txt");
    if (!file)
    {
        cout << "Error opening file.." << endl;
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

    if (found)
    {
        cout << "Roll number : " << student.roll_number << endl;
        cout << "Name  : " << student.name << endl;
        cout << "Division : " << student.division << endl;
        cout << "Address : " << student.address << endl;
        file.close();
    }
    else
    {
        cout << "Not found...";
    }
}

void delete_student()
{
    int roll_number;
    cout << "\nEnter the roll number:";
    cin >> roll_number;

    ifstream original_file("students.txt");
    if (!original_file)
    {
        cout << "Error opening file.." << endl;
        return;
    }
    ofstream temp_file("temp.txt");
    if (!temp_file)
    {
        cout << "Error opening file.." << endl;
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
        cout << "Student deleted successfully....";
    }
}
int main(int argc, char const *argv[])
{
    while (true)
    {
        int choice;
        cout << "\n1.Create\n2.Insert\n3.Display\n4.Delete\n5.Exit\nEnter the choice: ";
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
            display();
            break;
        case 4:
            delete_student();
            break;
        case 5:
            exit(0);
            break;

        default:
            cout << "Invalid input...";
            break;
        }
    }

    return 0;
}
