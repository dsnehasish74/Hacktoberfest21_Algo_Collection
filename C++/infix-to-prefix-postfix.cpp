#include <iostream>
#include<string>
using namespace std;

struct stack
{
    int top;
    int size;
    char elements[100];
    string str_ele[100];
};
void push_char(struct stack &s,char x)
{ 
    if(s.top==s.size-1)
    cout<<"Stack is full \n";
    else
    {
        s.elements[++s.top]=x;
    }
}
char peek_char(struct stack &s)
{
  if(s.top==-1)
    return 'a' ;
    else 
    return s.elements[s.top];   
}
char pop_char(struct stack &s)
{
   if(s.top==-1)
    return 'a' ;
    else 
    return s.elements[s.top--]; 
}
void push_string(struct stack &s,string x)
{ 
    if(s.top==s.size-1)
    cout<<"Stack is full \n";
    else
    {
        s.str_ele[++s.top]=x;
    }
}
string peek_string(struct stack &s)
{
  if(s.top==-1)
    return ".." ;
    else 
    return s.str_ele[s.top];   
}
string pop_string(struct stack &s)
{
    if(s.top==-1)
    return ".." ;
    else 
    return s.str_ele[s.top--];  
}
bool isoperator(char a)
{
    return (a=='*' || a=='/' || a=='-' || a=='+');
}
bool isbracket(char a)
{
    return (a=='(' || a==')'||a=='[' || a==']' || a=='{' ||a=='}' );
}
int operation(char c)
{
    switch(c){
        case '(' : return 0;
        case '+' : return 1;
        case '-' : return 2;
        case '*' : return 3;
        case '/' : return 4;
    }
    return -1;
}

string ques1(string str)
{
    string res="";
    int i;
    for(i=str.size()-1;i>-1;i--)
    res+=str[i];
    str=res;
    for(i=0;i<str.size();i++)
    {
        if(str[i]=='(')
        str[i]=')';
        else if(str[i]==')')
        str[i]='(';
    }
     res="";
     struct stack s1;
    s1.top=-1;
    s1.size=100;
    for(i=0;i<str.size();i++)
    {
        if(!isbracket(str[i]) && !isoperator(str[i]))
        res+=str[i];
        else if(s1.top==-1 || str[i]=='(')
            push_char(s1,str[i]);
         else if(str[i]==')')
                {
                    while(peek_char(s1)!='(')
                    res+=pop_char(s1);
                    pop_char(s1);
                }
         else
                {
                    while(operation(str[i])<operation(peek_char(s1)))
                    {
                        res+=pop_char(s1);
                       
                        if(s1.top==-1)
                        break;
                    }
                    push_char(s1,str[i]);
                }
     }
     while(s1.top>=0)
     {
         res+=pop_char(s1);
     }
    str="";
    for(i=res.size()-1;i>-1;i--)
    str+=res[i];
    return str;
}
string ques2(string str)
{
    int i,n=str.size();
    string res="";
    struct stack s2;
    s2.top=-1;
    s2.size=100;
    for(i=0;i<n;i++)
    {
        if(!isbracket(str[i]) && !isoperator(str[i]))
        res+=str[i];
        else if(s2.top==-1 || str[i]=='(')
            push_char(s2,str[i]);
         else if(str[i]==')')
                {
                    while(peek_char(s2)!='(')
                    res+=pop_char(s2);
                    pop_char(s2);
                }
         else
                {
                    while(operation(str[i])<=operation(peek_char(s2)))
                    {
                        res+=pop_char(s2);
                       
                        if(s2.top==-1)
                        break;
                    }
                    push_char(s2,str[i]);
                }
     }
     while(s2.top>=0)
     {
         res+=pop_char(s2);
     }
     return res;
    
}



int main()
{
    string q1,q2,q3;
    cout<<"Enter a infix :\n";
   cin>>q1;
   cout<<"infix to prefix :  "<<ques1(q1)<<"\n";
   cout<<"infix to postfix : "<<ques2(q1)<<"\n";
  
   
    return 0;
}
