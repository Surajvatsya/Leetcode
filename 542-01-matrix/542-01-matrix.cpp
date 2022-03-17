class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>>q;
        int n = mat.size();
        int m = mat[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]==0)
                    q.push({i,j});
                else
                    mat[i][j]=-1;
            }
        }
        
        while(!q.empty()){
            int a = q.front().first;
            int b = q.front().second;
            cout<<a<<" "<<b<<endl;
            q.pop();
            if( a+1<n  and  mat[a+1][b]==-1 ){
                mat[a+1][b]= mat[a][b]+1;
                q.push({a+1,b});
            }
             if( a-1>=0  and  mat[a-1][b]==-1){
                mat[a-1][b]= mat[a][b]+1;
                q.push({a-1,b}); 
            }
            if( b-1>=0 and mat[a][b-1]==-1  ){
                mat[a][b-1]= mat[a][b]+1;
                q.push({a,b-1}); 
            }
             if( b+1<m and mat[a][b+1]==-1 ){
                 mat[a][b+1]= mat[a][b]+1;
                q.push({a,b+1});
            }
            
        }
        
        return mat;
    }
};