#include <bits/stdc++.h>
using namespace std;
struct Stack
{
    int size;
    int top ;
    int *arr;
};

class Stack_Class
{
    Stack *object;

protected:
    bool isEmpty();
    bool isFull();

public:
    void creation();
    void push();
    void pop();
    void display();
};

bool Stack_Class ::isEmpty()
{
    if (object->top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Stack_Class ::isFull()
{
    if (object->top == object->size-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Stack_Class ::creation()
{
    int s;
    char ch = 'y';
    object->top= -1;
    cout << "Enter the size of the stack: ";
    cin >> s;
    object->size = s;
    object->arr = new int[object->size];
    while (ch == 'y' || ch == 'Y')
    {
        if (isFull())
        {
            cout << "The Stack is Full"<<endl;
            break;
        }
        else
        {

            object->top++;
            cout << "Enter the element " << object->top << " : ";
            cin >> object->arr[object->top];
            cout << endl;
            cout << "Do you want to enter more: ";
            cin >> ch;
        }
    }
}

void Stack_Class::display()
{
    for (int i = 0; i <=object->top; i++)
    {
        cout << object->arr[i] << " ";
    }
    cout << endl;
}

void Stack_Class ::push()
{
    if (isFull())
    {
        cout << "The stack is full"<<endl;
    }
    else
    {
        int element;
        cout << "Enter the element which you want to insert in the Stack: ";
        cin >> element;
        object->arr[object->top] = element;
        object->top++;
    }
}

void Stack_Class ::pop()
{
    if (isEmpty())
    {
        cout << "The Stack is empty"<<endl;
    }
    else
    {
        object->top--;
    }
}
int main()
{
    int choice;
    Stack_Class operations;
    do
    {
        cout << "1. Enter the array" << endl;
        cout << "2. Display the array" << endl;
        cout << "3. Push the element into the array" << endl;
        cout << "4. pop the value in the array" << endl;
        cout << "5. Exit" << endl;
        cout << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            operations.creation();
            break;
        }
        case 2:
        {
            operations.display();
            break;
        }
        case 3:
        {
            operations.push();
            break;
        }
        case 4:
        {
            operations.pop();
            break;
        }
        case 5:
        {

            break;
        }

        default:
        {
            cout << "WRONG CHOICE !!!!!!!!!" << endl;
            break;
        }
        }
    } while (choice != 5);
    return 0;
}