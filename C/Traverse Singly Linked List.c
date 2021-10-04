# include<stdio.h>
# include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};
struct node *insert_node_end(int data, struct node *head)
{
    struct node *temp, *p=head;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        while(p->link!=NULL)
        {
            p=p->link;
        }
        p->link=temp;
    }
    return head;
}
int main() {
    int n, i;
    struct node *head=NULL;
    printf("Enter the number of nodes you want to enter\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        int info;
        printf("Enter the data you want to enter\n");
        scanf("%d",&info);
        head=insert_node_end(info,head);
    }
    struct node *p1=head;
        while(p1!=NULL)
        {
            printf("%d ",p1->data);
            p1=p1->link;
        }
}

