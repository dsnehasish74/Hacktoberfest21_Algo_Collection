//Fractional Knapsack
#include<bits/stdc++.h>
using namespace std;
#define ll long long

double fractionalKnapsack(vector<int>weight, vector<int> value, int capacity){
    int n = weight.size();
    vector<pair<double, int>> value_per_unit_weight(n);
    double max_value = 0;
    int curr_weight = 0, total_weight= 0;

    for(int i = 0; i < n; i++){
        value_per_unit_weight[i].first = value[i] / weight[i];
        value_per_unit_weight[i].second = i;
        total_weight += weight[i];
    }

    sort(value_per_unit_weight.begin(), value_per_unit_weight.end());

    int i = n - 1;
    while (capacity != 0) {
        int num = min(capacity, weight[value_per_unit_weight[i].second]);
        capacity -= num;
        curr_weight += num;
        max_value += num * value_per_unit_weight[i].first;
        if (curr_weight == total_weight) break;
        i--;
    }
    return max_value;
}

int main(){
    vector<int> value = {60, 100};
    vector<int> weight = {10, 20};
    int capacity = 50;

    cout << fractionalKnapsack(weight, value, capacity) << endl;
}