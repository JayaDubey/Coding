#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(int src, stack<int> &s, vector<int> &vis, vector<int> adj[]){
	    vis[src] = 1;
	    for(auto it: adj[src]){
	        if(!vis[it])
	        dfs(it, s, vis, adj);
	    }
	    s.push(src);//stores all sources of thestrongly connected graph
	}
	void revDfs(int src, vector<int> &vis, vector<int> adj[]){
	    vis[src] = true;
	    for(auto it: adj[src]){
	        if(!vis[it])
	        revDfs(it, vis, adj);
	    }
	}
    int kosaraju(int V, vector<int> adj[])
    {
        stack<int> s;
        vector<int> tr[V];
        vector<int> vis(V, 0);
        //sort dfs acc to finish time
        for(int i = 0; i < V; i++){
            if(!vis[i])
              dfs(i, s, vis, adj);
        }
        //Reverse the graph (transpose)
        for(int i = 0; i < V; i++){
            for(auto it: adj[i])
            tr[it].push_back(i);//linking all adjacent nodes in reverse direction to its source
        }
        //make the visited array unvisited
        fill(vis.begin(), vis.end(), 0);
        int count = 0;
        while(!s.empty()){
            int src = s.top(); //source nodes
            s.pop();
            if(!vis[src]){
                count++; //for each source count
                revDfs(src, vis, tr);//traversing all its sub nodes
            }
        }
        return count;
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
