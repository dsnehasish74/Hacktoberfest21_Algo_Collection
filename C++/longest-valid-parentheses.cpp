
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string A;
    cin>>A;
    stack<int> s;
    int n = A.length(), i = 0;
    int res = 0;
    
    while(i < n){
        if(s.empty() || A[i] == '(' || (A[s.top()] == ')'))
            s.push(i);
        else{
            s.pop();
            int ans = s.empty() ? i + 1 : i - s.top();
            res = max(res, ans);
        }
        i++;
    }
    cout<<res<<endl;
    return 0;
}