class Solution {
public:
    bool issafe(int row,int col,  vector<string>&v, int n){
        //vertical
        for(int i=0; i<row; i++){
            if(v[i][col]=='Q')
                return false;
        }
        
        
        
        //diagonal left
        int i=row; int j=col;
            while(i>=0 and j>=0){
                if(v[i][j]=='Q')
                    return false;
                i--;
                j--;
            }
        
        
        
        
        //diagonal right
         i=row;  j=col;
        while(i>=0 and j<n){
            if(v[i][j]=='Q')
                    return false;
                i--;
                j++;
        }
        return true;
    }
    void solve(int n , vector<vector<string>>&ans,vector<string>&v,int x){
        //base case
        if(x==n)
        {
            ans.push_back(v);
            return;
        }
        
        
        for(int col=0; col<n; col++){
            if(issafe(x,col,v, n)){
                //do
                v[x][col]='Q';
                
                //recurr
                solve(n, ans, v, x+1);
                
                //undo
                v[x][col]='.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        //ans 
        vector<vector<string>>ans;
        
        //vector of string which I'll put in ans
        vector<string>v(n, string(n,'.'));
        
        //1st row where you will put queen
        int x= 0;
        solve(n, ans, v,x);
        return ans;
    }
};