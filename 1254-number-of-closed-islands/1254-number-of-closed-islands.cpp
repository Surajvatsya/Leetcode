class Solution {
public:
    
    void change(int i, int j,vector<vector<int>>& grid, int n, int m){
        if(i<0 or j<0 or i==n or j==m)
            return;
        if(grid[i][j]==0){
            grid[i][j]=-1;
            change(i+1,j,grid,n,m);
            change(i-1,j,grid,n,m);
            change(i,j+1,grid,n,m);
            change(i,j-1,grid,n,m);
        }
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(i==0 or j==0 or i==n-1 or j==m-1)
                    change(i,j,grid,n,m);
            }
        }
        int count = 0;
        
         for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j]==0)
                {
                    change(i,j,grid,n,m);
                    count++;
                }
                
            }
        }
        return count;
        
    }
};