class Solution {
public:
  
    
    bool isValid(vector<vector<int>>&v,int x, int y, int n){
        for(int i=0; i<x; i++){
            if(v[i][y]==1)
                return false;
        }
        
        int row = x;
        int col=y;
        
        while(row>=0 and col>=0){
            if(v[row][col]==1)
                return false;
            row--;
            col--;
                
        }
         row = x;
         col=y;
        
        while(row>=0 and col<n){
            if(v[row][col]==1)
                return false;
                row--;
            col++;
                
        }
        return true;
        
    }
    
    void solve(vector<vector<int>>&v, int row, int n, int &count){
        if(row==n){
            count++;
            return;
        }
        for(int col=0; col<n; col++){
            
            if(isValid(v,row,col,n)){
                //do
                v[row][col]=1;
                
                //reccur
                solve(v,row+1,n, count);
                
                //undo
                v[row][col]=0;
            }
        }
    }
    
    
    int totalNQueens(int n) {
          int count=0;
       vector<vector<int>>v(n, vector<int>(n,0));
        solve(v,0,n, count);
            return count;
    }
};