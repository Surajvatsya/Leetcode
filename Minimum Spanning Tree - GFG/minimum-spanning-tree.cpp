// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        int cost = 0;
        //itll form the original mst
        vector<int>parent(V, -1);
        
        //dis from u to v
        vector<int>dis(V,INT_MAX);
        
        //whether included in mst or not
        vector<int>vis(V,false);
        
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>pq;
        
        //value = 0 for index 0;
        pq.push({0,0});
        dis[0]=0;
        parent[0]=-1;
        while(!pq.empty()){
            int u = pq.top().second;
            pq.pop();
            vis[u]=true;
            for(auto it : adj[u]){
                int v = it[0];
                int wt = it[1];
                if(!vis[v] and wt<dis[v]){
                   
                    parent[v]=u;
                    dis[v]=wt;
                    pq.push({wt,v});
                    
                }
            }
        }
        for(auto &x : dis)
        cost+=x;
        return cost;
        
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends