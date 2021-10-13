#include<iostream>
using namespace std;
int main()
{
    int n, i, arr[50], j, temp;
    cout<<"Enter the Size (max. 50): ";
    cin>>n;
    cout<<"Enter "<<n<<" Numbers: ";
    for(i=0; i<n; i++)
        cin>>arr[i];
    cout<<"\nSorting the Array using Bubble Sort \n";
    for(i=0; i<(n-1); i++)
    {
        //Optimizing Bubble Sort
        bool flag=true;
        for(j=0; j<(n-i-1); j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag=false;
            }
        }
        //If No Swapping it means array is sorted at this point.
        if(flag)break;
    }
    cout<<"\nArray Sorted Successfully!\n";
    cout<<"\nThe New Array is: \n";
    for(i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}
