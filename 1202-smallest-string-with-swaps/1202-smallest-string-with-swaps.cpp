class Solution {
public:
    
    void dfs(string &s,  vector<int>&vis, vector<vector<int>>&adj, int curr,  vector<int>&ind,  vector<char>&c){
        
      
         vis[curr]=true;
        ind.push_back(curr);
        c.push_back(s[curr]);
        
        for(auto &x : adj[curr]){
            if(!vis[x])
                dfs(s,vis,adj,x,ind,c);
        }
        
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        //step1 make a adj list
        int n = s.size();
        vector<vector<int>>adj(n);
        for(auto &x : pairs){
            int u = x[0];
            int v = x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
         vector<int>vis(n,false);
        //not connected component k lye pura node pe traverse
        for(int i=0; i<n; i++){
            if(!vis[i]){
               vector<int>ind;
            vector<char>c;
            dfs(s,vis,adj,i,ind,c);
            sort(ind.begin(), ind.end());
            sort(c.begin(), c.end());
            for(int j=0;j<ind.size();j++){
                s[ind[j]]= c[j];
            } 
            }
            
        }
        return s;
    }
};