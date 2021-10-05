// Done by Sanjoy Saha
// Github user link - https://github.com/SanjoySaha24
// Cycle sort is an in-place sorting Algorithm, unstable sorting algorithm, a comparison sort that is theoretically optimal in terms of the total number of writes to the original array. 

#include<bits/stdc++.h> 
using namespace std; 

void cycleSortDistinct(int arr[], int n) 
{ 
    for(int cs=0;cs<n-1;cs++){
        int item=arr[cs];
        int pos=cs;
        for(int i=cs+1;i<n;i++)
            if(arr[i]<item)
                pos++;
        swap(item,arr[pos]);
        while(pos!=cs){
            pos=cs;
            for(int i=cs+1;i<n;i++)
                if(arr[i]<item)
                    pos++;
            swap(item,arr[pos]);
        }
    }
} 
  
int main() 
{ 
    int arr[] = { 20,40,50,10,30 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cycleSortDistinct(arr, n); 
   
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " ";
        
    return 0; 
} 