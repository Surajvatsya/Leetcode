class Solution {
public:
    
    void dfs( vector<vector<bool>>&oceanToLand,vector<vector<int>>& h, int i, int j, int n,int m){
         oceanToLand[i][j] = true;
        
        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,0};
        
        for(int k=0; k<4; k++){
            int cx = i + dx[k];
            int cy = j + dy[k];
             if(cx>=0 and cy>=0 and cx<n and cy<m and !oceanToLand[cx][cy] and h[cx][cy]>= h[i][j]  ){  
                  dfs(oceanToLand,  h, cx, cy, n, m);   
             }   
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        
        vector<vector<int>>ans;
        int n = h.size();
        int m = h[0].size();
        
        vector<vector<bool>>atlanticToLand(n, vector<bool>(m,false));
         vector<vector<bool>>pacificToLand(n, vector<bool>(m,false));
        
        for(int j=0; j<m; j++){
            dfs(pacificToLand,  h, 0,   j, n, m);
            dfs(atlanticToLand, h, n-1, j, n, m);
                
        }
        
        
         for(int i=0; i<n; i++){
            dfs(atlanticToLand, h, i, m-1, n, m );
            dfs(pacificToLand, h, i, 0, n, m);
                
        }
        
        
        
        //check 
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(atlanticToLand[i][j] and pacificToLand[i][j])
                    ans.push_back({i, j});
                    
            }
        }
        
        return ans;
    }
};