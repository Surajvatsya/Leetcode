class Solution {
public:
    
    bool solve(string s1, int i, string s2, int j, string s3, int k, string ans, vector<vector<int>>&dp){
     //base case
        
        if(i==s1.size() and j==s2.size()){
            return s3==ans;
        }
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        bool a = false, b=false;
        
        if( i<s1.size() and  s3[k]==s1[i]){
            
         a =   solve(s1,i+1,s2,j,s3,k+1,ans+s1[i], dp);
        }
        
         if(j<s2.size() and s3[k]==s2[j]){
           
         b=   solve(s1,i,s2,j+1,s3,k+1,ans+s2[j], dp); 
        }
        
         return dp[i][j] = a or b;   
    }
    
   
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        // vector<int>dp()
        string ans = "";
        int ind = 0;
        int i=0;
        int j=0;
        int k=0;
        return solve(s1,i,s2,j,s3,k,ans, dp);
        
    }
};