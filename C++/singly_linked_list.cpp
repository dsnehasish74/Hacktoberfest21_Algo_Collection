// Program to implement Singly-Linked list in cpp.

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void display();
struct node *first;
struct node *nn;
struct node *temp;
struct node *temp2;
int ele;

void insert_at_first_position()
{
    nn = (struct node *)malloc(sizeof(struct node));
    printf("ENTER ELEMENT TO INSERT AT FIRST POSITION :");
    scanf("%d",&nn->data);

    nn->next = first;
    first = nn;
}

void insert_at_last_position()
{
     nn = (struct node *)malloc(sizeof(struct node));
     printf("ENTER ELEMENT TO INSERT AT LAST POSITION :");
     scanf("%d",&nn->data);

         nn->next = NULL;

         temp = first;

         while(temp->next != NULL)
         {
             temp = temp->next;
         }
         temp->next = nn;
}

void insert_at_selected_position()
{
        nn = (struct node *)malloc(sizeof(struct node));
        printf("ENTER ELEMENT WHICH YOU WANT TO INSERT :");
        scanf("%d",&nn->data);

        display();

        printf("\nENTER ELEMENT AFTER WHICH YOU WANT TO INSERT THIS ELEMENT : ");
        scanf("%d",&ele);

        temp = first;
        while(temp->data != ele)
        {
            temp = temp->next;
        }

        nn->next = temp->next;
        temp->next = nn;
}

void remove_from_first_position()
{
    if(first == NULL)
    {
        printf("LINKED LIST IS NOT CREATED YET, NOTHING TO DISPLAY\n");
    }
    else
    {
        temp = first;
        first = first->next;

        printf("REMOVED ELEMENT IS %d",temp->data);
    }
}

void remove_from_last_position()
{
    if(first == NULL)
    {
        printf("LINKED LIST IS NOT CREATED YET, NOTHING TO DISPLAY\n");
    }
    else
    {
        temp = first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp2 = first;

        while(temp2->next != temp)
        {
            temp2 = temp2->next;
        }
        printf("REMOVED ELEMENT IS %d",temp2->next->data);
        temp2->next = NULL;
    }
}

void remove_from_selected_position()
{
    if(first == NULL)
    {
        printf("\nLINKED LIST IS NOT CREATED YET, NOTHING TO DISPLAY\n\n");
    }
    else
    {
        display();
        printf("ENTER ELEMENT WHICH YOU TO REMOVE : ");
        scanf("%d",&ele);

        if(first->data == ele)
        {
            first = first->next;
           printf("REMOVED ELEMENT IS : %d",ele);
        }
        else
        {
            temp = first;
            while(temp->data != ele)
            {
                temp = temp->next;
            }

            temp2 = first;
            while(temp2->next != temp)
            {
                temp2 = temp2->next;
            }

            temp2->next = temp->next;

            printf("REMOVED ELEMENT IS : %d",temp->data);
        }
    }
}

void search_operation()
{
    int i=1;
    int flag=1;
    if(first == NULL)
    {
        printf("\nLL IS NOT CREATED YET, NOTHING TO DISPLAY\n");
    }
    else
    {
        printf("\nENTER THE ELEMENT WHICH YOU WANT TO SEARCH :");
        scanf("%d",&ele);

        temp = first;
      while(temp != NULL)
      {
          if(temp->data == ele)
          {
              printf("%d IS PRESENT AT LOCATION %d ", ele, i);
              flag = 1;
              break;
          }
          else
          {
              flag = 2;
          }
          i++;
          temp = temp->next;
       }

       if(flag == 2)
       {
           printf("\n %d IS NOT IN LINKED LIST",ele);
       }
    }
}

void sort_operation()
{
    int demo;
    if(first == NULL)
    {
        printf("\nLL IS NOT CREATED YET, NOTHING TO DISPLAY\n");
    }
    else
    {
        temp = first;

       while(temp != NULL)
       {
           temp2 = temp->next;
           while(temp2 != NULL)
           {
               if(temp->data > temp2->data)
               {
                   demo = temp->data;
                   temp->data = temp2->data;
                   temp2->data = demo;
               }
               temp2 = temp2->next;
           }
           temp = temp->next;
       }
    }
}

void display()
{
    if(first == NULL)
    {
        printf("LINKED LIST IS NOT CREATED YET, NOTHING TO DISPLAY");
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
        printf("\n1 - INSERT ELEMENT AT FIRST POSITION\n");
        printf("2 - INSERT ELEMENT AT LAST POSITION\n");
        printf("3 - INSERT ELEMENT AT SELECTED POSITION POSITION\n");
        printf("4 - REMOVE FROMT THE FIRST POSITION\n");
        printf("5 - REMOVE FROMT THE LAST POSITION\n");
        printf("6 - REMOVE FROMT THE SELECTED POSITION\n");
        printf("7 - SEARCH OPERATION\n");
        printf("8 - SORT OPERATION\n");
        printf("9 - DISPLAY\n");
        printf("10 - EXIT");

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

            case 7: search_operation();
            break;

            case 8: sort_operation();
            break;

            case 9: display();
            break;

            case 10: exit(0);
            break;

            default: printf("\n INVALID CHOICE \n\n");
        }
    }while(1);

    return 0;
}
