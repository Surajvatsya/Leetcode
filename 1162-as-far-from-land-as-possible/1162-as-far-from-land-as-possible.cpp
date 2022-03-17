class Solution {
public:
    int maxDistance(vector<vector<int>>& mat) {
     int n = mat.size();
        if(n==0)
            return 0;
        
        int m = n;
        queue<pair<int,int>> q;
        
        for(int i=0; i<n; i++){
            for(int j=0;j<n; j++){
                if(mat[i][j]==1){
                    mat[i][j]=0;
                     q.push({i,j});
                }
                else{
                    mat[i][j]=-1;
                }
                   
            }
        }
        int ans = -1;
        
        while(!q.empty()){
            int a = q.front().first;
            int b = q.front().second;
           
            q.pop();
            if( a+1<n  and  mat[a+1][b]==-1 ){
                mat[a+1][b]= mat[a][b]+1;
                q.push({a+1,b});
                ans = max(ans, mat[a+1][b]);
            }
             if( a-1>=0  and  mat[a-1][b]==-1){
                mat[a-1][b]= mat[a][b]+1;
                q.push({a-1,b}); 
                  ans = max(ans, mat[a-1][b]);
            }
            if( b-1>=0 and mat[a][b-1]==-1  ){
                mat[a][b-1]= mat[a][b]+1;
                q.push({a,b-1}); 
                 ans = max(ans, mat[a][b-1]);
            }
             if( b+1<m and mat[a][b+1]==-1 ){
                 mat[a][b+1]= mat[a][b]+1;
                q.push({a,b+1});
                  ans = max(ans, mat[a][b+1]);
            }
            
        }
        
        return ans;
        
    }
};