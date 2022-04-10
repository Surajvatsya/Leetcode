class Solution {
public:
    
    bool issafe(int x, int y, int n, vector<string>&v){
        
        for(int row = 0; row<=x; row++){
            if(v[row][y]=='Q')
                return false;
        }
        int row = x;
        int col = y;
        while(row>=0 and col>=0){
            if(v[row][col]=='Q')
                return false;
            row--;
            col--;
        }
        
        row = x;
        col = y;
        while(row>=0 and col<n){
            if(v[row][col]=='Q')
                return false;
            row--;
            col++;
        }
        
        return true;
    }
    
    
    void isnqueen( vector<vector<string>>& ans, vector<string>&v, int x, int n){
        if(x>=n){
            ans.push_back(v);
            return ;
        }
        
        for(int col=0; col<n; col++){
           
            if(issafe(x,col,n,v)){
                 //do
                v[x][col]='Q';
                
            //recurr
            isnqueen(ans,v,x+1,n);
        
            
            //undo
            v[x][col]='.';
            }
                
                
        }
        
    }
    
    
    vector<vector<string>> solveNQueens(int n) {
         vector<vector<string>> ans;
         vector<string>v(n,string(n,'.'));
        
        isnqueen(ans, v,0,n);
            
        return ans;
        
    }
};