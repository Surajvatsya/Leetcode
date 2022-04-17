class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
            int mn = INT_MAX;
        
        if(n==1){
            return matrix[0][0];
        }
            
        
        for(int i=1; i<n; i++){
            for(int j = 0; j<m; j++){
                if(j==0){
                   matrix[i][j] += min(matrix[i-1][j], matrix[i-1][j+1]); 
                }
                else if(j==m-1){
                    matrix[i][j] += min(matrix[i-1][j], matrix[i-1][j-1]); 
                }
                else{
                    matrix[i][j] += min(min(matrix[i-1][j], matrix[i-1][j+1]),  matrix[i-1][j-1]); 
                }
                if(i==n-1)
                mn = min(mn, matrix[i][j]);
            }
        }
        return mn;
    }
};