class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        if(n==0)
            return -1;
    
        
        
        queue<pair<int,int>>q;
        int count=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2)
                    q.push({i,j});
                if(grid[i][j]!=0)
                    count++;
            }
        }
        
        if(count==0)
            return count;
        cout<<count<<endl;
        int time = -1;
        while(!q.empty()){
            time++;
            int sz = q.size();
            count-=sz;
            for(int i=0; i<sz; i++){
                pair<int,int> p = q.front();
                q.pop();
                
                int x = p.first;
                int y = p.second;
                // cout<<x<<" "<<y<<endl;
                int dx[] = {1,-1,0,0};
                int dy[] = {0,0,-1,1};
                for(int j=0; j<4; j++){
                    int cx = x+ dx[j];
                    int cy = y + dy[j];
                    if(cx>=0 and cx<n and cy>=0 and cy<m and grid[cx][cy]==1){
                        grid[cx][cy] = 2;
                        q.push({cx,cy});
                    }
                }
            }
            
            
            
        }
        cout<<count<<endl;
        
       return count==0?time:-1;
       
        
    }
};