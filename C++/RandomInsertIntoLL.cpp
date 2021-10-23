#include<iostream>
using namespace std;
class node
{
  public:
  int val;
  node* link;
}*head,*last;
void insert(int n,int pos)
{    
  node* temp=new node();
  temp->val=n;
  temp->link=NULL;
  if(head==NULL)
    head=temp;
    else if(pos==1)
    {
        temp->link=head;
        head=temp;
    }
else{
  node* tempr=head;
  node* templ=NULL;
  int c=0;
  while(c<pos)
  {
      templ=tempr;
      tempr=tempr->link;
      c++;
  }
  if(tempr->link==NULL)
  {
      templ->link=temp;
      temp->link=NULL;
  }
  else{
  templ->link=temp;
  temp->link=tempr;
  }
}
}
void display()
{
    node* temp=head;
    while(temp)
    {
        cout<<temp->val<<" -> ";
        temp=temp->link;
    }
}
int main()
{
  head=NULL;
  last=NULL;
  int n_ele=0;
  while(true)
  {
    int x,pos;
    cin>>pos>>x;
    pos--;
    if(pos<0 || pos>n_ele+1)
      break;
    display();
    insert(x,pos);
    display();
    n_ele++;
  }
    cout<<"Invalid position"<<endl;
  return 0;
}
