#include <iostream>
using namespace std;

int duplicate(int arr[])
{
    int slow = arr[0];
    int fast = arr[0];

    do
    {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);

    slow = arr[0];

    while (slow != fast)
    {
        slow = arr[slow];
        fast = arr[fast];
    }

    return slow;
}

int main()
{
    int arr[] = {1,2,4,3,3,5,6};

    cout<<duplicate(arr);

    return 0;
}