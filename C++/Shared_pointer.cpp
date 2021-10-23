#include<iostream>
#include<memory>
using namespace std;

class foo
{
    int x;

    public:

    foo(int x):x(x)
    {}

    int getx()
    {return x;}

    ~foo()
    {
        cout<<"DESTRUCT"<<endl;
    }

};

int main()
{
   // foo *f=new foo(35);             // the problem is that we forgot to destroy the DMA block, hence it leads to memory leak.  
   // cout<<f->getx()<<endl;          // Using delete will be necessary in this but as we can't always remember to do so. SO WE USE UNIQUE POINTER.
                                       //  delete f;

 // Another Method  shared_ptr<foo> sp(new foo(35));   
   shared_ptr<foo> sp = make_shared<foo>(35);            //   The advantages of shared pointer is that it will destroy the memory block it is pointing to when the
   cout<<sp->getx()<<endl;                               // last remaining shared_ptr (pointing to object) will get destroyed, and obviously when object is gonna destroyed, the destructor will be called.                
   shared_ptr<foo> sp1=sp;
   shared_ptr<foo> sp2=sp;                              // &sp2=sp; AND *sp2=&sp; will not work.                                
   cout<<sp.use_count()<<endl;
   shared_ptr<foo> sp3=sp;
  cout<<sp3.use_count()<<endl;                   //Destructor will run only once regardless of how many shared_ptrs are pointing to the object.
}                                                       // It is a smart pointer with reference-count copy semantics..
                                                          // Actually, in shared_ptr : we have two things 1)First is your object(memory block) you created called Managed object.
                                                          // 2) Second One is called Control block, which come in act when we assign the VALUE of one shared_ptr to other, it increases
                                                          // the reference count with the same. 
