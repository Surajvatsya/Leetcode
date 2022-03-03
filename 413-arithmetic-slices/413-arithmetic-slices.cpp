class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& v) {
        
        int n = v.size();
        if(n<3)
            return 0;
        // vector<int>dp(n,0);
          long sum = 0;
        // for(int i=2; i<n; i++){
        //     if(v[i]-v[i-1] == v[i-1]-v[i-2])
        //         dp[i]=dp[i-1]+1;
        //     sum+=dp[i];
        // }
        // return sum;
        
        int cnt = 0;
        for(int i=2; i<n; i++){
            if(v[i]-v[i-1] == v[i-1]-v[i-2])
            {
                  cnt++;
                sum+=cnt;
            }
            else
                cnt=0;
        }
        return sum;
    }
        
};