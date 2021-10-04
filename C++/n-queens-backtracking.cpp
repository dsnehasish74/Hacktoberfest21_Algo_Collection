#include<bits/stdc++.h>
using namespace std;

int board[11][11];

bool isPossible(int n,int row,int col){
    for(int i=row-1;i>=0;i--){
        if(board[i][col]==1)return false;
    }
    for(int i=col-1,j=row-1;i>=0&&j>=0;i--,j--){
        if(board[j][i]==1)return false;
    }
    for(int i=col+1,j=row-1;i<n&&j>=0;i++,j--){
        if(board[j][i]==1)return false;
    }
    return true;
    
}


void nQueensHelper(int n, int row){
    if(row==n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<board[i][j]<<" ";
            }
        }
        cout<<endl;
        return;
    }
    for(int i=0;i<n;i++){
        if(isPossible(n,row,i)){
            board[row][i]=1;
			nQueensHelper(n,row+1);
            board[row][i]=0;
        }
    }
    
}

void nQueens(int n){
  memset(board,0,11*11*sizeof(int));
    nQueensHelper(n,0);
}

int main(){
    int n;
    cin>>n;
    nQueens(n);
    return 0;
}
