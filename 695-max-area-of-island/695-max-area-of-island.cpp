class Solution {
public:
    
    void dfs(vector<vector<int>>& grid, int i, int j , int & count, int n, int m){
        if (i < 0 || j < 0 || i >= n || j >= m)
 			return;
        
        if(grid[i][j]==1){
            count++;
            grid[i][j]=-1;
            
        dfs(grid, i+1, j, count, n, m);
 		dfs(grid, i-1, j, count, n, m);
 		dfs(grid, i, j+1, count, n, m);
 		dfs(grid, i, j-1, count, n, m);
        }
        
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
       if (grid.empty()) return 0;

 		int n = grid.size();
 		int m = grid[0].size();
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int count = 0;
                if(i==0 or i==n-1 or j==0 or j==m-1){
                    dfs(grid,i,j, count,n,m);
                    ans = max(ans, count);
                }
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int count = 0;
                if(grid[i][j]==1){
                    dfs(grid,i,j, count,n,m);
                    ans = max(ans, count);
                }
            }
        }
        
        return ans;
        
    }
};