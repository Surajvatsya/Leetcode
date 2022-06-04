class Solution {
public:
    
    bool isValid(vector<string>&v, int x, int y, int n){
        for(int i=0; i<=x; i++){
            if(v[i][y]=='Q')
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
    
    void solve(vector<vector<string>>&ans, vector<string>&v, int n, int x){
        //base case
        if(x==n)
        {
            ans.push_back(v);
            return;
        }
        //check valid pos
        
        for(int col=0; col<n; col++){
            if(isValid(v,x,col,n)){
                //do
                v[x][col]='Q';
                
                //recurr
                solve(ans,v,n,x+1);
                
                //undo
                v[x][col]='.';
            }
        }
        
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string>v(n,string(n,'.'));
        int x=0;
       
        solve(ans,v,n,x);
        return ans;
        
    }
};