class Solution {
public:
    
    bool iscycle(vector<vector<int>>&g,vector<int>&stack, vector<int>&vis, int src){
        vis[src] = true;
        stack[src] = true;
        
        for(auto &x:g[src]){
            if(!vis[x] and iscycle(g,stack,vis,x)){
                return true;
            }
            else if(stack[x]==true)
                return true;
        }
        stack[src]=false;
        return false;
    }
    
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int N = numCourses;
        int n = prerequisites.size();
         vector<vector<int>>g(N);
        for(int i=0; i<n; i++){
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            g[u].push_back(v);
        }
        
        vector<int>stack(N,false);
        vector<int>vis(N,false);
        
        for(int i=0; i<N; i++){
            
            if(!vis[i] and iscycle(g,stack,vis,i)){
                return false;
            }
        }
        return true;
    }
};