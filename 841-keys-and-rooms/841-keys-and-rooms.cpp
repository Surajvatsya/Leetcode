class Solution {
public:
    
    void dfs(vector<vector<int>>& rooms, vector<bool>&vis, int idx){
        for(auto &x : rooms[idx]){
            if(!vis[x]){
                vis[x]=true;
               dfs(rooms, vis,x);
            }
        }
        
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n = rooms.size();
        vector<bool>vis(n,false);
        vis[0]=true;
        
        dfs(rooms, vis,0);
        
        for(int i = 0; i<n ; i++){
            if(!vis[i])
                return false;
        }
        return true;
        
    }
};