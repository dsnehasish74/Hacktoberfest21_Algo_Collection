#include<iostream>
#include<vector>
using namespace std;

void swap(vector<int> &arr, int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void dutchFlagSort(vector<int> &arr){
    int low = 0, high = arr.size() - 1;
    for(int i = 0; i <= high;){
        if (arr[i] == 0){
            swap(arr, i, low);
            i++;
            low++;
        } else if (arr[i] == 1){
            i++;
        } else{ 
            swap(arr,i,high);
            high--;
        }
    }
}

int main(){

    vector<int> arr = {1,0,2,1,0,2,1,0,2,2,1,0};
    dutchFlagSort(arr);
    for(auto num : arr)
        cout << num << " ";
    
    cout << endl;

    return 0;
}