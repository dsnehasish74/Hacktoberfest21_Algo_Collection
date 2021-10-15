// Program to implement Linked list in cpp.

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *first;

void insert_node()
{
    struct node *nn;
    struct node *temp;

    nn = (struct node *)malloc(sizeof(struct node));

    printf("ENTER ELEMENT :");
    scanf("%d",&nn->data);
    nn->next = NULL;

    if(first ==  NULL)
    {
        first = nn;
    }
    else
    {
        temp = first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = nn;
    }
}

void display()
{
    struct node *temp;
    if(first == NULL)
    {
        printf("\nLINKED LIST IS YET NOT CREATED, NOTHING TO DISPLAY");
    }
    else
    {
        temp = first;
        while(temp != NULL)
        {
            printf("%d\n",temp->data);
            temp = temp->next;
        }
    }
}

int main()
{
    int ch;
    first = NULL;

    do
    {
        printf("\n1 - INSERT\n");
        printf("2 - DISPLAY\n");
        printf("3 - EXIT\n");

        printf("PROVIDE YOUR CHOICE : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: insert_node();
            break;

            case 2: display();
            break;

            case 3: exit(0);
        }
    }while(1);

    return 0;
}
