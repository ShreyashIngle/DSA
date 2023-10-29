#include <iostream>
#include <string.h>
#include <conio.h>
#include <cmath>
using namespace std;

struct student
{
    int roll;
    float sgpa;
    string name;
};

class se
{
    student s[100], temp;

private:
    int d = 0;

public:
    int n;

public:
    void getdata()
    {
        // int n;
        cout << "ENTER NO OF STUDENTS" << endl;
        cin >> n;
        cout << "ENTER DETAILS" << endl;
        for (int i = d; i < d + n; i++)
        {
            cout << "Enter the roll Number : ";
            cin >> s[i].roll;
            cout << "Enter name of student : ";
            cin >> s[i].name;
            cout << "Enter sgpa of the student : ";
            cin >> s[i].sgpa;
            int c = getchar();
        }
        d = d + n;
    }

    void display()
    {
        cout << "\nROll NO\t\tName\t\tSGPA";
        for (int i = 0; i < d; i++)
        {
            cout << "\n"
                 << s[i].roll << "\t\t" << s[i].name << "\t\t" << s[i].sgpa;
        }
    }

    void duplicate()
    {
        for (int i = 0; i < d; i++)
        {
            for (int j = i + 1; j < d; j++)
            {
                if (s[i].roll == s[j].roll)
                {
                    cout << "\n\t" << s[i].roll << "  This roll number already exists\n\t";
                    break;
                }
            }
            break;
        }
    }

    void sortByName()
    {
        int j = 0;
        for (int i = 0; i < d; i++)
        {
            int tem = s[i].roll;
            string tem_name = s[i].name;
            double temp_sgpa = s[i].sgpa;
            j = i + 1;
            while (j < n)
            {
                if (s[j].name < tem_name)
                {
                    tem = s[j].roll;
                    tem_name = s[j].name;
                    temp_sgpa = s[j].sgpa;
                    swap(s[i], s[j]);
                }
                j++;
            }
            s[i].name = tem_name;
            s[i].roll = tem;
            s[i].sgpa = temp_sgpa;
        }
        cout << "DATABASE SORTED ALPHABETICALLY" << endl;
    }

    void sortByRoll()
    {
        int i;
        for (i = 0; i < d; i++)
        {
            for (int j = i + 1; j < d; j++)
            {
                if (s[i].roll >= s[j].roll)
                {
                    temp = s[j];
                    s[j] = s[i];
                    s[i] = temp;
                }
            }
        }
        cout << "DATABASE SORTED ON THE BASIS OF ROLL NO" << endl;
    }

    void rollSearch()
    {
        float k;
        cout << "ENTER THE ROLL NUMBER YOU WANT TO SEARCH : ";
        cin >> k;
        for (int i = 0; i < d; i++)
        {
            if (s[i].roll == k)
            {
                cout << "ROll NO\t\tName\t\tSGPA";
                cout << "\n"
                     << s[i].roll << "\t\t" << s[i].name << "\t\t" << s[i].sgpa;
                cout << endl
                     << endl;
            }
        }
    }

    void NameSearch()
    {
        string name_call;
        cout << "Enter the Name to be searched: ";
        cin >> name_call;
        int low = 0;
        int high = n - 1;
        while (low <= high)
        {
            int mid = floor((low + high) / 2);
            if (s[mid].name == name_call)
            {
                cout << name_call << " is present in SE09." << endl;
                cout << "Given name is present at index " << mid << "." << endl;
                cout << "The details of the student are as follows:"
                     << "\n"
                     << "Roll No.: " << s[mid].roll << "\n"
                     << "CGPA: " << s[mid].sgpa << endl;
                break;
            }
            else if (name_call < s[mid].name)
            {
                high = mid - 1;
            }
            else if (name_call > s[mid].name)
            {
                low = mid + 1;
            }
        }
    }
};

int main()
{
    se p;
    int ch;
    p.getdata();
    p.duplicate();
    p.display();

    do
    {
        cout << "\n----------------MENU----------------\n";
        cout << " 1.Input and Display \n 2.Sort by ROll no \n 3.Sort by Name \n 4.Name search \n 5.Exit\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            p.getdata();
            p.duplicate();
            p.display();
            break;

        case 2:
            p.sortByRoll();
            p.display();
            break;

        case 3:
            p.sortByName();
            p.display();
            break;

        case 4:
            p.NameSearch();
            break;

        case 5:
            exit(0);
        }
    } while (ch != 5);

    return 0;
}
