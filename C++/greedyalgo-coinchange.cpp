/*
  Author Lakshay Goel
  Github profile: https://github.com/MrLakshay
  Problem statement : Given coins worth 1 ,5 and 10 in unlimited quantity need to find 
                    minimum number of coins 'x' to make 'n' sum of money input by user.
  Input: n
  Output : x
  Exampple:
  17
  4
*/
#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    cout<<t/10+((t%10)/5)+((t%10)%5)/1;
}
