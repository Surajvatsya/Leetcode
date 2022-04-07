class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        
        vector<int>adj[n+1];
        for(int i=0; i<dislikes.size(); i++){
            int u = dislikes[i][0];
            int v = dislikes[i][1];
            adj[u].push_back(v);
                 adj[v].push_back(u);
        }
        
        
        queue<int>q;
        
        vector<int> color(n+1, -1);
        
        for(int i=1; i<=n; i++){
            if(color[i]!=-1)
                continue;
            
            color[i]=0;
            q.push(i);
            
            while(!q.empty()){
                int ele = q.front();
                q.pop();
                
                for(auto &x : adj[ele]){
                    if(color[x]==-1){
                        color[x] = 1- color[ele];
                        q.push(x);
                    }
                    else if(color[x]==color[ele])
                        return false;
                }
            }
        }
        return true;
    }
};