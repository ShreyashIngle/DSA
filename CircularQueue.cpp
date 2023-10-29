#include <iostream>
using namespace std;
#define max 10

class CircularQueue
{
    int data[max];
    int f = -1;
    int r = -1;

public:
    int is_full()
    {
        if ((r + 1) % max == f)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int is_empty()
    {
        if (r == -1 && f == -1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    void enqueue(int a)
    {
        int output = is_full();
        if (output == 1)
        {
            cout << "The queue is full, no elements can be added further" << endl;
        }
        else
        {
            if (r == -1)
            {
                f++;
                r++;
                data[r] = a;
            }
            else
            {
                r = (r + 1) % max;
                data[r] = a;
            }
        }
    }

    void dequeue()
    {
        int output = is_empty();
        if (output == 1)
        {
            cout << "The queue is already empty, can't delete any elements further" << endl;
        }
        else
        {
            int x;
            if (f == r)
            {
                x = data[f];
                cout << "Deleted element: " << x << endl;
                f = -1;
                r = -1;
            }
            else
            {
                x = data[f];
                f = (f + 1) % max;
                cout << "Deleted element: " << x << endl;
            }
        }
    }

    void display()
    {
        int counter;
        int output;
        int diff;
        output = is_empty();
        if (output == 1)
        {
            cout << "The queue is empty" << endl;
        }
        else
        {
            diff = r - f;
            if (diff >= 0)
            {
                counter = diff + 1;
                for (int i = 0; i < counter; i++)
                {
                    cout << data[(f + i) % max] << " ";
                }
                cout << endl;
            }
            else
            {
                counter = max + diff + 1;
                for (int i = 0; i < counter; i++)
                {
                    cout << data[(f + i) % max] << " ";
                }
                cout << endl;
            }
        }
    }

    void search()
    {
        int key;
        int counter;
        int diff;
        int count = 0;
        cout << "Enter number to be searched: ";
        cin >> key;
        int output = is_empty();
        if (output == 1)
        {
            cout << "The queue is empty" << endl;
        }
        else
        {
            diff = r - f;
            if (diff >= 0)
            {
                counter = diff + 1;
                for (int i = 0; i < counter; i++)
                {
                    if (data[(f + i) % max] == key)
                    {
                        cout << "The element '" << key << "' is present at the index '" << ((f + i) % max) << "'" << endl;
                        count++;
                    }
                }
                if (count == 0)
                {
                    cout << "The element is '" << key << "' is not present in the queue" << endl;
                }
            }
            else
            {
                counter = max + diff + 1;
                for (int i = 0; i < counter; i++)
                {
                    if (data[(f + i) % max] == key)
                    {
                        cout << "The element '" << key << "' is present at the index '" << ((f + i) % max) << "'" << endl;
                        count++;
                    }
                }
                if (count == 0)
                {
                    cout << "The element '" << key << "' is not present in the queue" << endl;
                }
            }
        }
    }
};

int main()
{
    CircularQueue q;
    int choice;
    int exit = 0;
    int num;

    do
    {

        cout << "-------------------------------" << endl;
        cout << "             MENU              " << endl;
        cout << "-------------------------------" << endl;
        cout << "1. Insert number" << endl;
        cout << "2. Delete number" << endl;
        cout << "3. Display Queue" << endl;
        cout << "4. Search number in Queue" << endl;
        cout << "5. Exit" << endl
             << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "-------------------------------" << endl;

        switch (choice)
        {
        case 1:

            cout << "Enter number: ";
            cin >> num;

            q.enqueue(num);

            cout << endl
                 << "Elements Added Successfully...." << endl
                 << endl;
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.display();
            break;
        case 4:
            q.search();
            break;
        case 5:
            exit = choice;
            break;
        default:
            cout << "Invalid Input!" << endl;
            break;
        }
    } while (exit != 5);

    return 0;
}
