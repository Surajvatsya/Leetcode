class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        int n = t.size();
        int m = t[n-1].size();
        
        
        int dp[n][m];
        for(int i = n-1; i>=0; i--){
            for(int j = t[i].size()-1; j>=0; j--){
                if(i==n-1){
                    dp[i][j]=t[i][j];
                }
                else{
                    dp[i][j] = t[i][j]+min(dp[i+1][j+1],dp[i+1][j]);
                }
            }
        }
        return dp[0][0];
        
        
        
    }
};