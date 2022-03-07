class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n);
        dp[0]=1;
        int ans = 1;
        for(int i=1; i<n; i++){
            int mx = 0;
            for(int j = 0; j<i; j++){
                if(nums[i] > nums[j])
                mx = max(mx, dp[j]);
            }
            dp[i] = 1+mx;
            ans = max(ans, dp[i]);
        }
        // int ans = 1;
        // for(auto &x : dp){
        //     ans = max(ans, x);
        // }
        return ans;
    }
};