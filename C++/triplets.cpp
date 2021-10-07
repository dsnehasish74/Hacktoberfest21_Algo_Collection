#include <bits/stdc++.h>
using namespace std;


// Function to efficiently find out three elements whose sum is equal to a given sum
// Time complexity : O(n2)

vector< vector<int> > triplets(vector <int> arr, int Sum) 
{
    vector < vector<int> > res;

    int n = arr.size();

    for (int i = 0; i <= n-3; ++i)
    {
        int j = i+1;
        int k = n-1;

        while(j < k)
        {
            int currsum = arr[i] + arr[j] + arr[k];
            if(currsum == Sum){
                res.push_back({arr[i] , arr[j] , arr[k]});
                j++;
                k--;
            }
            else if(currsum > Sum)
                k--;
            else
                j++;
        }
    }
    return res;
}

int main()
{
    // Example 
    vector <int> v = {1,2,3,4,5,6,7,8,9,15};
    int Sum = 32;

    auto p = triplets(v,Sum);

    if(p.size()==0)
        cout << "No pair found" ;
    else
    {
        for (auto triplet : p)
        {
            // Outputting all valid triplet sets
            for(auto ans : triplet)
                cout << ans << " ";
            cout << endl;
        }
    }
}
