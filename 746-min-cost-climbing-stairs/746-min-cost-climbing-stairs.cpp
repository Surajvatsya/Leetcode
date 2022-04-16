class Solution {
public:
    // int minCostClimbingStairs(vector<int>& cost) {
    //     int n = cost.size();
    //     vector<int>dp(n+1);
    //     dp[0]=cost[0];
    //     dp[1]=cost[1];
    //     for(int i=2; i<n; i++ ){
    //         dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
    //     }
    //     dp[n] = min(dp[n-1],dp[n-2]);
    //     return dp[n];
    // }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // vector<int>dp(n+1);
        // dp[0]=cost[0];
        // dp[1]=cost[1];
        for(int i=2; i<n; i++ ){
            cost[i] = cost[i] + min(cost[i-1],cost[i-2]);
        }
        // dp[n] = min(dp[n-1],dp[n-2]);
        return min(cost[n-1],cost[n-2]);
    }
    
};