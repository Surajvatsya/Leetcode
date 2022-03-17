class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n==0)
            return 0;
        
        int level = -1;
        int count = 0;
        queue<pair<int,int>>q;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1)
                {
                    q.push({i,j});
                    count++;
                }
            }
        }
        
        if(count==n*n)
            return -1;
        
        
        while(!q.empty()){
            int sz = q.size();
            level++;
            for(int i=0; i<sz; i++){
               pair<int,int>p = q.front(); 
                q.pop();
                int x = p.first;
                int y = p.second;
                
                int dx[] = {-1,1,0,0};
                int dy[] = {0,0,1,-1};
                for(int j=0; j<4; j++){
                    int cx = x + dx[j];
                    int cy = y + dy[j];
                    if(cx>=0 and cy>=0 and cx<n and cy<n and grid[cx][cy]==0){
                        grid[cx][cy]=grid[cx][cy] + 1;
                        q.push({cx,cy});
                    }
                }
                
            }
        }
        return level;
        
    }
};