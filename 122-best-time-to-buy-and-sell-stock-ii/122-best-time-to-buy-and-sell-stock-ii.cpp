class Solution {
public:
    
    int solve(int i, vector<int>& prices, bool buy, int n,  vector<vector<int>>&dp){
        //base case
        if(i>=n)
            return 0;
        
        if(dp[i][buy]!=-1)
            return dp[i][buy];
        
        int profit = 0;
        //buy
        if(buy){
            profit = max(
                //take or buy
                -prices[i] +  solve(i+1,prices,0,n, dp) ,
                //not take or not buy
                0 + solve(i+1,prices,1,n, dp)
                );
            
         }
        //sell
        //ek sath buy or sell nai hoga n
        else{
            profit = max(
                //sell
                prices[i] + solve(i+1,prices,1,n, dp) ,
                //not sell
                        0 + solve(i+1,prices,0,n, dp));
            
        }
        
        return dp[i][buy] =  profit;
        
    }
    
    int maxProfit(vector<int>& prices) {
        bool buy = 1;
        int n = prices.size();
        //index and buy both are changing so 2d dp
        vector<vector<int>>dp( n, vector<int>(2, -1));
        
        return solve(0,prices,buy,n, dp);
    }
};