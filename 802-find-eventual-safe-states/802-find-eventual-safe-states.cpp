class Solution {
public:
    
    
    
     bool iscycle(int src,  vector<bool>&vis,vector<vector<int>>& graph,  vector<bool>&stack, vector<bool>&cycle){
            vis[src]=true;
            stack[src]=true;
            for(auto &x : graph[src]){
                if(!vis[x] and iscycle(x,vis,graph, stack,cycle))
                    return cycle[src] = true;
                else if(stack[x]){
                    return cycle[src] = true;
                }
            }
            //yha single node ko consider kro
            stack[src]=false;
            return false;
        }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>safe;
        int n = graph.size();
        vector<bool>vis(n,false);
        vector<bool>stack(n,false);
        vector<bool>cycle(n,false);
        
       
        
        
        for(int i=0; i<n; i++){
            if(!vis[i])
                iscycle(i,vis,graph, stack,cycle);
        }
        
        for(int i=0; i<n; i++){
            if(!cycle[i])
                safe.push_back(i);
        }
        return safe;
    }
};