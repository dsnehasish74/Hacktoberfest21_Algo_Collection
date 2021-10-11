// 0/1 Knapsack using memoization
#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<int>> dp(4, vector<int>(51, -1));
int knapsack(int capacity, vector<int> weight, vector<int> val, int n) {
    if(capacity < 0){
        return -1;
    }
    if (capacity == 0 || n == 0) {
        dp[n][capacity] = 0;
    }
    if (dp[n][capacity] != -1) {
        return dp[n][capacity];
    }
    if (weight[n - 1] > capacity) {
        dp[n][capacity] = knapsack(capacity, weight, val, n - 1);
        return dp[n][capacity];
    } else {
        dp[n][capacity] = max(val[n - 1] + knapsack(capacity - weight[n - 1], weight, val, n - 1), knapsack(capacity, weight, val, n - 1));
        return dp[n][capacity];
    }
}

int main() {
    vector<int> val = {60, 100, 120};
    vector<int> weight = {10, 20, 30};
    int capacity = 50;
    int n = val.size();
    cout << knapsack(capacity, weight, val, n);
}