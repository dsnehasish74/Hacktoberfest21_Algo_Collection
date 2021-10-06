//Given a graph representing a flow network where every edge has a capacity. 
//Given source 's' and sink 't' in graph, find maximum flow from s to t
#include<bits/stdc++.h>
using namespace std;

#define V 6

bool bfs(int rgraph[V][V], int src, int t, int parent[])
{
    vector<bool>visited(V, false);
    queue<int>q;
    q.push(src);
    visited[src] = true;
    parent[src] = -1;

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(int v=0; v<V; v++)
        {
            if(visited[v]==false && rgraph[u][v] >0)
            {
                if(v==t)
                {
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return false;

}

int ford_fulk(int graph[V][V], int src, int t)
{
    int u,v;
    int rgraph[V][V];
    for(u=0; u<V; u++)
    {
        for(v=0; v<V; v++)
            rgraph[u][v] = graph[u][v];
    }

    int parent[V];

    int max_flow = 0; // intially 0 flow

    //augment flow till there is a path from source to sink
    while(bfs(rgraph, src, t, parent))
    {   
        //find residual capacity of the edges along the path filled by BFS
        int path_flow = INT_MAX;
        for(v=t; v!=src; v = parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, rgraph[u][v]);
        }

        for(v=t; v!=src; v=parent[v])
        {
          u = parent[v];
          rgraph[u][v] -= path_flow;
          rgraph[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;

}

int main()
{   
    int v = 6;
    int graph[V][V] = { { 0, 16, 13, 0, 0, 0 }, { 0, 0, 10, 12, 0, 0 },
            { 0, 4, 0, 0, 14, 0 },  { 0, 0, 9, 0, 0, 20 },
            { 0, 0, 0, 7, 0, 4 },   { 0, 0, 0, 0, 0, 0 } };
    cout<<"The max possible flow of graph is:  "<<ford_fulk(graph, 0, 5);
    return 0;
}