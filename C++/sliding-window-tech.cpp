#include <bits/stdc++.h>
using namespace std;
 

int maxSum(int arr[], int n, int k)
{
    // Initialize result
    int max_sum = INT_MIN;
 
    // Consider all blocks starting with i.
    for (int i = 0; i < n - k + 1; i++) {
        int curr_sum = 0;
        for (int j = 0; j < k; j++)
            curr_sum = curr_sum + arr[i + j];
 
        // Update result if required.
        max_sum = max(curr_sum, max_sum);
    }
 
    return max_sum;
}

int main()
{
    int arr[] = { 1, 4, 2, 10, 2, 3, 1, 0, 20 };
    int k = 4;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxSum(arr, n, k);
    return 0;
}