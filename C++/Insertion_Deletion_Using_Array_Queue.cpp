#include <bits/stdc++.h>
using namespace std;
class Queue_operation
{
    int arr[1000];
    int frontInd = -1;
    int rearInd = -1;

protected:
    bool isfull();
    bool isempty();

public:
    void insertElements_in_queue();
    void enqueue();
    void dequeue();
    void display();
};

bool Queue_operation::isfull()
{
    if (rearInd == 999)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Queue_operation::isempty()
{
    if (frontInd == rearInd)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Queue_operation::display()
{
    if (isempty())
    {
        cout << "Queue is Empty" << endl;
    }
    else
    {
        cout << "The elements present in the queue is: ";
        for (int i = frontInd; i < rearInd; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

void Queue_operation::insertElements_in_queue()
{
    int count = 0;
    char ch = 'y';
    int element;
    while (ch == 'y' || ch == 'Y')
    {
        if (isfull())
        {
            cout << "The queue is Full" << endl;
            return;
        }
        else
        {
            cout << "Enter the " << count + 1 << " element which you want to insert in the queue: ";
            cin >> element;
            if (frontInd == -1 || rearInd == -1)
            {
                frontInd = rearInd = 0;
            }

            arr[count] = element;
            rearInd++;
            count++;

            cout << "Do you want to enter more: ";
            cin >> ch;
        }
    }
}
void Queue_operation::dequeue()
{
    int element;
    if (isempty())
    {
        cout << "Queue is Empty" << endl;
        return ;
    }
    else
    {
        element= arr[frontInd];
        frontInd++;
        cout<<"The removed Element is: "<<element<<endl;

    }


}

void Queue_operation::enqueue()
{
    if (isfull())
    {
        cout << "The queue is Full" << endl;
    }
    else
    {

        int element;
        cout << "Enter the Element which you want  to insert in the queue: ";
        cin >> element;
        arr[rearInd] = element;
        rearInd++;
    }
}

int main()
{
    int choice;
    Queue_operation operations;
    do
    {
        cout << "1. Insertion in the queue" << endl;
        cout << "2. Display the queue" << endl;
        cout << "3. Perform the  enqueue operation" << endl;
        cout << "4. Perform the dequeue operation" << endl;
        cout << "5. Exit" << endl;
        cout << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            operations.insertElements_in_queue();
            break;
        }
        case 2:
        {
            operations.display();
            break;
        }
        case 3:
        {
            operations.enqueue();
            break;
        }
        case 4:
        {

            operations.dequeue();
            break;
        }
        case 5:
        {

            break;
        }

        default:
        {
            break;
        }
        }
    } while (choice != 5);

    return 0;
}