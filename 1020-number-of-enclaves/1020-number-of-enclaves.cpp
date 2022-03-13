class Solution {
public:
    
    void change(int i, int j, vector<vector<int>>& grid){
       
        if(i<0 or i==grid.size() or j<0  or j==grid[0].size())
           return;
        
             if(grid[i][j]==1){
                    grid[i][j]=-1;
                     change(i+1,j,grid);
                     change(i-1,j,grid);
                     change(i,j-1,grid);
                     change(i,j+1,grid);    
            }  
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        
        if(grid.size()==0)
            return 0;
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(i==0 or i==grid.size()-1 or j==0 or j==grid[i].size()-1){
                    if(grid[i][j]==1)
                      change(i,j,grid);
                }
            }
        }
        int count = 0;
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j]==1){
                    
                  //count cell
                    count++;
                }
                
            }
        }
        
        return count;
        
    }
};