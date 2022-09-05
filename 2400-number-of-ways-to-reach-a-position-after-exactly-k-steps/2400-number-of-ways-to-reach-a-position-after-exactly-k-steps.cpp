class Solution {
public:
    
  
    int mod = 1000000007; 
    
  
    
    
    int  solve(int startPos, int endPos, int k,  vector< vector<int> >&dp){
        if(k==0)
        {
            if(startPos==endPos)
                 return 1;
            return 0;
        }

         if(abs(startPos- endPos) > k) return 0;

        if(dp[startPos + 1001][k]!=-1)
           return dp[startPos + 1001][k];
                
        
        //ahead
       
       int a =   solve(startPos+1,endPos,k-1, dp);
        
        
        //back
        
        
         int   b =  solve(startPos-1,endPos,k-1, dp);
        
        
      return dp[startPos+1001][k] = (a+b)%mod;
        
    }
    
    int numberOfWays(int startPos, int endPos, int k) {
       vector< vector<int> >dp(3005, vector<int>(k+1, -1));
        if(abs(endPos - startPos)==k)
            return 1;
        if(abs(endPos - startPos) > k)
            return 0;
        
      
        
       return  solve(startPos,endPos,k, dp);
        
         
    }
};
