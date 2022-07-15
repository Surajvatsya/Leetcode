class Solution {
public:
    
    int solve(int n,  vector<int>&dp){
        if(n==2)
            return 1;
        if(dp[n]!=-1)
            return dp[n];
        int maxi=0;
        for(int i=1; i<n; i++){
            int l = solve(n-i, dp)*i;
            int r = (n-i)*i;
            int val = max(l,r);
            maxi = max(maxi, val);
            
        }
        return dp[n] = maxi;
    }
    
    
    int integerBreak(int n) {
        vector<int>dp(n+1, -1);
         return solve(n, dp);
    }
};