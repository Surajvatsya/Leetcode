class Solution {
public:
    int solve(int i, int n, vector<int>& nums, int p_i ,  vector<vector<int>>&dp){
        //base case
        
        if(i>=n)
            return 0;
        
       if(dp[i][p_i+1]!=-1)
           return dp[i][p_i+1];
           
    //not take
        int len = solve(i+1,n,nums,p_i, dp);
        
        
         //take
        if(p_i==-1 or nums[i]>nums[p_i])
           len =max(len,  1 + solve(i+1,n,nums,i, dp));
        
        
        return dp[i][p_i+1] = len;
        
    }
    
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
    vector<vector<int>>dp(n,vector<int>(n+1,-1) );
        return solve(0,n,nums, -1,dp);
    }
};