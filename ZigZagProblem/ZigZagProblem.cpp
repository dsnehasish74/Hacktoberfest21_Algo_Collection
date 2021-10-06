/*ZigZag Problem
Take input of number of rows and columns.
Print the following zigzag pattern.
Sample Input :
7 16
Sample Output :
1                       13 
  2                  12  14
    3              11        15
      4          10             16
        5      9
          6  8
            7
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int row, column;
    cin >> row >> column;
    vector<vector<int>> matrix(row, vector<int>(column,0));

    int a = 0, b = 0;
    bool Zigzag = true;
    while(b<column){
        matrix[a][b] = b+1;
       if(a==0){
           Zigzag = true;
       }else if(a==(row-1)){
           Zigzag = false;
       }
        if(Zigzag){
            a++;
        }else{
            a--;
        }
        b++;
    }

    for (int a = 0; a < row;a++){
        for (int b = 0; b < column;b++){
            if(matrix[a][b]!=0){
                cout << matrix[a][b] << " ";
            }else{
                cout << "  ";
            }

        }
        cout << endl;
    }
}