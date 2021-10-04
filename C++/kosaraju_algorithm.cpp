//Gfg- Strongly Connected Components (Kosaraju's Algo)
//https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	
	int vis[100001];

	void dfs1(int node,vector<int> adj[],stack<int>& st){
	    vis[node]=1;
	    for(int i:adj[node])
	        if(!vis[i]) dfs1(i,adj,st);
	    st.push(node);
	}
	
	void dfs2(int node,vector<int> adj[]){
	    vis[node]=1;
	    for(int i:adj[node])
	        if(!vis[i]) dfs2(i,adj);
	}


	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        memset(vis,0,sizeof(vis));
        stack<int> st;
        vector<int> trans[V];
        for(int i=0;i<V;i++) {
            for(int j:adj[i])
                trans[j].push_back(i);
        }
        
        for(int i=0;i<V;i++)
            if(!vis[i]) dfs1(i,adj,st);
        
        memset(vis,0,sizeof(vis)); 
        int ans=0;
        while(!st.empty()){
            int x = st.top();
            st.pop();
            if(!vis[x]) {
                dfs2(x,trans);
                ans++;
            }
        }
        
        return ans;
    }
};


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}
