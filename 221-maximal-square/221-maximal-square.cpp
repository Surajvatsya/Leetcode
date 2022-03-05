class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>v(n, vector<int>(m,0));
        
        int mx = 0;
        for(int i= n-1;i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(i==n-1 or j==m-1){
                    if(matrix[i][j]=='1')
                        v[i][j]=1;
                }
                else if(matrix[i][j]!='0'){
                    v[i][j] = 1 + min( v[i+1][j+1], min( v[i][j+1],v[i+1][j]));
                }
                    mx = max(mx, v[i][j]);
            }
        }
        
        return mx*mx;
    }
};

