#include<iostream>
#include<conio.h>
using namespace std;
int maxhepify(int a[],int n,int i)
{
    int largest=i;
    int l=(2*i)+1;
    int r=(2*i)+2;
    while(l<n&&a[l]>a[largest])
        {largest=l;}
    while(r<n&&a[r]>a[largest])
        {largest=r;}
    if(largest!=i)
    {
        swap(a[largest],a[i]);
        maxhepify(a,n,largest);
    }
}
int heap_sort(int a[],int n)
{
    int i;
    for(i=n/2-1;i>=0;i--)
        maxhepify(a,n,i);
    for(i=n-1;i>=0;i--)
    {
        swap(a[0],a[i]);
        maxhepify(a,i,0);
    }
}
int main()
{
    int i,n;
    cout<<"enter size of array:";
    cin>>n;
    int a[n];
    cout<<"enter elements of array:";
    for(i=0;i<n;i++)
        cin>>a[i];
    cout<<"before sorting:"<<endl;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    heap_sort(a,n);
    cout<<"\nafter sorting:"<<endl;
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
}
