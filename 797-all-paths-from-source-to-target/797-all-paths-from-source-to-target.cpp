class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int idx, int target, vector<vector<int>>& graph,vector<int>&v){
        //base case
        if(idx==target){
            ans.push_back(v);
            return;
        }
        // int li = v.size()-1;
        for(auto &x : graph[idx]){
            //do
            v.push_back(x);
            
            //recurr
            dfs(x,target,graph, v);
            
            //undo
            v.pop_back();
        }
         
        
        
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
       
        int n = graph.size();
        vector<int>v;
        v.push_back(0);
        dfs(0,n-1,graph, v);
        return ans;
        
        
    }
};