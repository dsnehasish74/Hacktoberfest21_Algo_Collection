#include<bits/stdc++.h>
using namespace std;
class que
{
   stack<int>s1;
   //stack<int>s2;

   public:

   void push(int x)
   {
       s1.push(x);
   }

   int pop()
   {
       if (s1.empty())
       {
           cout<<"Stack is empty"<<endl;
           return -1;
       }
          int x= s1.top();
          s1.pop();
          if (s1.empty())
          {
              return x;
          }
           
            int item=pop(); //recursevily call
            s1.push(x);
            return item;
   }

  bool empty()
  {
         if (s1.empty())
       
           return true;
           return false;
  }

};

int main()
{
    que q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.pop();
    q.pop();
   cout<< q.pop();

    return 0;
}










// #include<bits/stdc++.h>
// using namespace std;

// class que
// {
//    stack<int>s1;
//    stack<int>s2;

//    public:

//    void push(int x)
//    {
//        s1.push(x);
//    }

//    int pop()
//    {
//        if (s1.empty() && s2.empty())
//        {
//            cout<<"Stack is empty"<<endl;
//            return -1;
//        }
       
//        if (s2.empty())
//        {
//            while (!s1.empty())
//            {
//                s2.push(s1.top());
//                s1.pop();
//            }
//        }
       
//         int topval=s2.top();
//         s2.pop();
//         return topval;
//    }

//   bool empty()
//   {
//          if (s1.empty() && s2.empty())
       
//            return true;
//            return false;
//   }

// };

// int main()
// {
//     que q;
//     q.push(1);
//     q.push(2);
//     q.push(3);
//     q.push(4);
//     q.pop();
//     q.pop();
//    cout<< q.pop();

//     return 0;
// }
