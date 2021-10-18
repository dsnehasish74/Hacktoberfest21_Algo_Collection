

#include <iostream>
using namespace std;
 
struct node
{
 char data;
 node *next;
 node(char d)
 {
 data = d;
 next = NULL;
 }
};
 
struct mystack
{
 node *head;
 int sz;
 mystack()
 {
 head = NULL;
 sz = 0;
 }
 
void push(char x)
{
 node *temp = new node(x);
 temp->next = head;
 head = temp;
 sz++;
}
 
char pop()
{
 if(head==NULL)
 {//underflow
 return '-';
 }
 char res = head->data;//res to be popped
 node *temp=head;//to prevent memory leak
 head = head->next;// ask head to point at new head
 delete(temp);//delete temp i.e. old head
 sz--;
 return res;
}
 
int size()
{
 return sz;
}
 
bool isEmpty()
{
 return (head==NULL);
}
 
char peek()
{
 if(head == NULL)
 {//underflow
 return '-';
 }
 return head->data;
}
 
};
 
int main() {
 mystack s;
 string str;
 cout << " Enter sting to chk for balanced parenthesis: ";
 cin >> str;
 for(int i=0;i<str.size();i++)
 {
 if(s.isEmpty() == true)
 {
 s.push(str[i]);
 }
 else
 {
 if(s.peek()=='{' && str[i] == '}')
 {
 s.pop();
 //continue;
 }
 else if(s.peek()=='[' && str[i] == ']')
 {
 s.pop();
 //continue;
 }
 else if(s.peek()=='(' && str[i] == ')')
 {
 s.pop();
 //continue;
 }
 else 
 {
 s.push(str[i]);
 }
 }
 }
 if (s.isEmpty()==true)
 {
 cout << "Balanced!" <<endl;
 }
 else
 {
 cout << "Not Balanced!" <<endl;
 }
 
 /*while(s.isEmpty()==false)
 {
 cout << s.peek();
 s.pop();
 }*/
}


 
 
