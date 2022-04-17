class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int>dp(n, -1);
        return solve(days, costs, 0, dp);
        
    }
    int solve(vector<int>& days, vector<int>& costs, int i, vector<int> &dp){
        int n = days.size();
        if(i>=days.size())
            return 0;
        
        
        if(dp[i]!=-1)
            return dp[i];
        int op1 = costs[0] + solve(days, costs, i+1, dp);
        
        int k;
        for( k = i; k<n; k++){
            if(days[k] >= days[i]+7)
                break;
        }
        
        int op2 = costs[1] + solve(days, costs, k, dp);
        
        for(k = i; k<n; k++){
            if(days[k] >= days[i]+30)
                break;
        }
        
         int op3 = costs[2] + solve(days, costs, k, dp);
        
        return dp[i] = min(min(op1, op2), op3);
        
    }
    
};