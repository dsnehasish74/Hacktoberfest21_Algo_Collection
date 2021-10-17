#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <string.h>
using namespace std;
#define ll long long int
#define rep(a, b, c) for (ll a = b; a < c; a++)
//O(nlogn)  divide and concour
void shellsort(int a[],int n){
    for(int gap=n/2;gap>0;gap/=2){
        for(int j=gap;j<n;j++){
            int temp=a[j];
            int i=0;
            for(i=j;(i>=gap) && (a[i-gap]>temp);i-=gap){
                a[i]=a[i-gap];

            }
            a[i]=temp;
        } 
    }
   
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    rep(i, 0, n)
    {
        cin >> a[i];
    }
    shellsort(a, n);
    rep(i, 0, n)
    {
        cout << a[i] << " ";
    }
    return 0;
}
