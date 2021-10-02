#include <bits/stdc++.h>
using namespace std;
  
int binarySearch(int arr[], int left, int right, int target)
{
    if (right >= left) {
        int mid = left + (right - left) / 2;
  
        //If target is equal to middle element
        if (arr[mid] == target)
            return mid;
  
        // If element is smaller than mid, then it can only be present in left subarray
        if (arr[mid] > target)
            return binarySearch(arr, left, mid - 1, target);
  
        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, right, target);
    }
  
    //If element is not present in array
    return -1;
}
  
int main(void)
{
    int n; //size of array
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int target;  //that element which we have to find in the array
    cin>>target;

    int result = binarySearch(arr, 0, n - 1, target);
    (result == -1) ? cout << "Element is not present in array" : cout << "Element is present at index " << result;
                   
    return 0;
}