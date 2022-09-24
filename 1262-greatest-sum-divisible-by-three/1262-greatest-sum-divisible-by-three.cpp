class Solution
{
    public:
    
    int solve(int i, int rem,vector<int> &nums,  vector<vector < int>> &dp ){
        if(i>=nums.size()){
            if(rem==0)
                return 0;
            return INT_MIN;
        }
        
        if(dp[i][rem]!=-1)
            return dp[i][rem];
        
        //pick
        int pick =  nums[i] +  solve(i+1, (rem+nums[i])%3, nums, dp);
        
        //not pick
        int npick =  solve(i+1, rem, nums, dp);
        
        
        return  dp[i][rem] = max(pick, npick);
    }
    
    
        int maxSumDivThree(vector<int> &nums)
        {
            int n = nums.size();
            vector<vector < int>> dp(n + 1, vector<int>(3,-1));
            return solve(0, 0, nums, dp);
        }
};