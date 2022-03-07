class Solution {
public:
    int numSquares(int n) {
        if(n<=3)
            return n;
        
        int dp[n+1];
        dp[0] = 0;
        for(int i = 1; i<n+1; i++){
            int mn = INT_MAX;
           for(int j = 1; j*j<=i; j++ ){
               
               int rem = i - j*j;
               mn = min(mn, dp[rem]);  
           }
              dp[i] = 1+ mn;
        }
         return dp[n];              
    }
};