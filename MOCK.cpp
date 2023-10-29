#include <iostream>
using namespace std;
#define max 10
class CQueue
{
public:
    int data[max];
    int f = -1;
    int r = -1;

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
            cout << "the queue is full cant add!!!";
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
            cout << "Queue is empty cant delete an element!!!" << endl;
        }
        else
        {
            int x;
            if (f == r)
            {
                x = data[f];
                cout << "Deleted element:" << x << endl;
            }
            else
            {
                x = data[f];
                f = (f + 1) % max;
                cout << endl
                     << "Deleted element:" << x << endl;
            }
        }
    }

    void display()
    {
        int output;
        int counter;
        int diff;

        output = is_empty();
        if (output == 1)
        {

            cout << "The queue is empty!!" << endl;
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
        int count = 0;
        int diff;
        int output = is_empty();

        cout << "Enter the number to be search:";
        cin >> key;

        if (output == 1)
        {
            cout << "The queue is empty!!" << endl;
        }
        else
        {
            diff = r - f;
            if (diff >= 0)
            {
                /* code */
                counter = diff + 1;
                for (int i = 0; i < counter; i++)
                {
                    /* code */
                    if (data[(f + i) % max] == key)
                    {
                        cout << "The element " << key << " is present at " << (f + i) % max << endl;
                        count++;
                    }
                }
                if (count == 0)
                {
                    cout << "The element " << key << " is not present  " << endl;
                }
            }
            else
            {
                counter = max + diff + 1;
                for (int i = 0; i < counter; i++)
                {
                    /* code */
                    if (data[(f + i) % max] == key)
                    {
                        cout << "The element " << key << " is present at " << (f + i) % max << endl;
                        count++;
                    }
                }
                if (count == 0)
                {
                    cout << "The element " << key << " is not present  " << endl;
                }
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    CQueue q;
    int choice;
    int exit=0;

    do
    {
    cout << "\n1.Insert\n2.Delete\n3.Display\n4.Search\n5.Exit\n\nEnter the choice: ";
    cin >> choice;
    cout<<endl;
        switch (choice)
        {
        case 1:
            int a;
            cout << "Enter the element to insert: ";
            cin >> a;
            q.enqueue(a);
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
        cout<<endl<<"Invalid input!!!";
            break;
        }
    }while (exit !=5);
    
    
    return 0;
}
