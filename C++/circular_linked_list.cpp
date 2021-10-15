// Program to implement Circular Linked_list in cpp.

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *first;
struct node *last;
int count = 0;
void display();
void insert_at_first_position()
{
    struct node *nn;
    nn = (struct node *)malloc(sizeof(struct node));
    printf("ENTER ELEMENT TO INSERT AT FIRST POSITION :");
    scanf("%d",&nn->data);
    if(first == NULL)
    {
        first = nn;
        last = nn;
    }
    else
    {
        nn->next = first;
        first = nn;
        last->next = nn;
    }
    count++;
}

void insert_at_last_position()
{
    struct node *nn;
    nn = (struct node *)malloc(sizeof(struct node));
    printf("ENTER ELEMENT TO INSERT AT LAST POSITION :");
    scanf("%d",&nn->data);
    if(first == NULL)
    {
        first = nn;
        last = nn;
    }
    else
    {
        last->next = nn;
        last = nn;
        last->next = first;
    }
    count++;
}

void insert_at_selected_position()
{
    struct node *nn;
    struct node *temp;
    int ele;
    nn = (struct node *)malloc(sizeof(struct node));
    printf("ENTER ELEMENT WHICH YOU WANT TO INSERT : ");
    scanf("%d",&nn->data);
    if(first == NULL)
    {
        first = nn;
        last = nn;
    }
    else
    {
        display();
        printf("ENTER ELEMENT AFTER WHICH YOU WANT TO INSERT THIS ELEMENT : ");
        scanf("%d",&ele);
        temp = first;
        while(temp->data != ele)
        {
            temp = temp->next;
        }
        nn->next = temp->next;
        temp->next = nn;
    }
    count++;
}

void remove_from_first_position()
{
    struct node *temp;
    if(first == NULL)
    {
        printf("LINKED LIST IS NOT CREATED YET, NITHING TO DISPLAY");
    }
    else
    {
        temp = first;
        first = first->next;
        last->next = first;
       printf("REMOVED ELEMENT IS : %d",temp->data);
       free(temp);
    }
    count--;
}


void remove_from_last_position()
{
    struct node *temp;
    struct node *temp2;
    if(first == NULL)
    {
        printf("LINKED LIST IS NOT CREATED YET. NITHING TO DISPLAY");
    }
    else
    {
        temp = first;
        while(temp->next != last)
        {
            temp = temp->next;
        }
        temp->next = first;
        temp2 = last;
        last = temp;
        printf("REMOVED ELEMENT IS : %d",temp2->data);
        free(temp2);
    }
    count--;
}

void remove_from_selected_position()
{
    int ele;
    struct node *temp;
    struct node *temp2;
    if(first == NULL)
    {
        printf("LINKED LIST IS NOT CREATED YET. NITHING TO DISPLAY");
    }
    else
    {
        printf("LINKED LIST CONTAINS :\n");
        display();
        printf("ENTER ELEMENT WHICH YOU WANT TO REMOVE :");
        scanf("%d",&ele);
        temp = first;

        do
        {
            if(temp->data == ele)
            {
                break;
            }
            temp = temp->next;
        }while(temp != first);
        if(temp == first)
        {
            printf("%d IS NOT PRESENT IN LINKED LIST",ele);
        }
        else
        {
            temp2 = first;
            while(temp2->next != temp)
            {
                temp2 = temp2->next;
            }
            temp2->next = temp->next;
            printf("REMOVED ELEMENT IS : %d",temp->data);
            free(temp);
        }
    }
    count--;
}

void display()
{
    struct node *temp;
    temp = first;
    if(temp == NULL)
    {
        printf("LINKED LIST IS NOT CREATED YET. NITHING TO DISPLAY");
    }
    else
    {
        for(int i=1;i<=count;i++)
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
    last = NULL;

    do
    {
        printf("\n1 - INSERT ELEMENT AT FIRST POSITION\n");
        printf("2 - INSERT ELEMENT AT LAST POSITION\n");
        printf("3 - INSERT ELEMENT AT SELECTED POSITION POSITION\n");
        printf("4 - REMOVE FROMT THE FIRST POSITION\n");
        printf("5 - REMOVE FROMT THE LAST POSITION\n");
        printf("6 - REMOVE FROMT THE SELECTED POSITION\n");
        printf("7 - DISPLAY\n");
        printf("8 - EXIT");
        printf("\nPROVIDE YOUR CHOICE :");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: insert_at_first_position();
            break;
            case 2: insert_at_last_position();
            break;
            case 3: insert_at_selected_position();
            break;
            case 4: remove_from_first_position();
            break;
            case 5: remove_from_last_position();
            break;
            case 6: remove_from_selected_position();
            break;
            break;
            case 7: display();
            break;
            case 8: exit(0);
            break;
            default: printf("\n INVALID CHOICE \n\n");
        }
    }while(1);
    return 0;
}
