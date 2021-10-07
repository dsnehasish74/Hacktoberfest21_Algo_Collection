#include <bits/stdc++.h>
using namespace std;
struct Stack
{
    int data;
    Stack *next;
};
class Stack_Operation
{
    Stack *top;
    Stack *ptr;

protected:
    void position_reset();
    bool isEmpty();

public:
    void insertion();
    void display();
    void push();
    void pop();
};

bool Stack_Operation::isEmpty()
{
    if (top == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Stack_Operation::position_reset()
{
    ptr = top;
}

void Stack_Operation::insertion()
{
    int size;
    int data;
    cout << "Enter the size of the stack: ";
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        Stack *new_node = new Stack;
        cout << "Enter the data which you want to insert in the stack: ";
        cin >> data;
        new_node->data = data;
        new_node->next = NULL;
        if (i == 0)
        {
            top = new_node;
        }
        else
        {
            new_node->next = top;
            top = new_node;
        }
    }
}

void Stack_Operation::display()
{
    position_reset();
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

void Stack_Operation::push()
{
    Stack *pushNode = new Stack;
    int data;
    cout << "Enter the data you want to push in the Stack: ";
    cin >> data;
    pushNode->data = data;
    pushNode->next = top;
    top = pushNode;
}

void Stack_Operation::pop()
{
    if (isEmpty())
    {
        cout<<"The Stack is Empty"<<endl;
    }
    else
    {
        Stack *delete_node = top;
        top = top->next;
        delete delete_node;
    }
}

int main()
{
    int choice;
    do
    {
        Stack_Operation operations;
        cout << "1. Insert the values in the Stack" << endl;
        cout << "2. display the stack" << endl;
        cout << "3. push the element in the stack" << endl;
        cout << "4. pop the element in the stack" << endl;
        cout << "5. Exit" << endl;
        cout << endl;
        cout << "Enter the choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            operations.insertion();
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
            cout << "Wrong Choice!!!!!!!!!!!!!!!";
            break;
        }
        }

    } while (choice != 5);
    return 0;
}