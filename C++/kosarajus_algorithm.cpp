#include<bits/stdc++.h>
using namespace std;
void DFS(vector<vector<int>> grid,stack<int> &temp,int start,vector<bool> &visited)
{
    visited[start]=true;
    for(int i=0;i<grid.size();i++)
        if(grid[start][i]==1 and i!=start and visited[i]==false)
        {
            DFS(grid,temp,i,visited);
        }
    temp.push(start);
}
void DFS(vector<vector<int>> grid,int start,vector<bool> &visited)
{
    visited[start]=true;
    for(int i=0;i<grid.size();i++)
        if(grid[start][i]==1 and i!=start and visited[i]==false)
        {
            DFS(grid,i,visited);
        }
    cout<<start<<",";
}
void kosaraju(vector<vector<int>> grid,int n)
{
    stack<int> temp;
    vector<bool> visited={false,false,false,false,false,false,false,false};
    // visited[0]=true;
    DFS(grid,temp,0,visited);
    for(int i=0;i<n;i++)
        if(visited[i]==false)
            DFS(grid,temp,i,visited);
    for(int i=0;i<n;i++)
        for(int j=0;j<i;j++)
        {
            int temp = grid[i][j];
            grid[i][j]=grid[j][i];
            grid[j][i]=temp;
        }
    visited={false,false,false,false,false,false,false,false};
    int start=temp.top();
    temp.pop();
    cout<<"(";
    DFS(grid,start,visited);
    cout<<")";
    while(temp.size()>0)
    {
        start=temp.top();
        temp.pop();
        if(visited[start]==false)
            {
            cout<<"(";
            DFS(grid,start,visited);
            cout<<")";
            }
    }
}
int main()
{
    vector<vector<int>> grid={{0,1,0,0,0,0,0,0},
                              {0,0,1,0,0,0,0,0},
                              {1,0,0,1,0,0,0,0},
                              {0,0,0,0,1,0,0,0},
                              {0,0,0,0,0,1,0,1},
                              {0,0,0,0,0,0,1,0},
                              {0,0,0,0,1,0,0,1},
                              {0,0,0,0,0,0,0,0}
                            };
    cout<<"Strongly connected components are: ";
    kosaraju(grid,8);
    return 0;
}