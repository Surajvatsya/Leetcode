class Solution {
public:
    
   int  countSubset(vector<int>& nums, int tr){
       int n = nums.size();
       int t[n+1][tr+1];
       for(int i=0; i<n+1; i++){
           for(int j=0; j<tr+1; j++){
               if(i==0)
                   t[i][j]=0;
               
           }
       }
       
       t[0][0]=1;
        for(int i=1; i<n+1; i++){
           for(int j=0; j<tr+1; j++){
               if(nums[i-1]<=j)
                   t[i][j]=t[i-1][j-nums[i-1]] +  t[i-1][j] ;
               else 
                   t[i][j] = t[i-1][j];
               
           }
       }
       
       return t[n][tr];
       
   }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int s=0;
        for(int i=0; i<nums.size(); i++)
            s+=nums[i];
        int t = (target + s)/2;
        if(abs(target) > s ||(target + s)%2!=0)
            return 0;
        return countSubset(nums,t);
        
        
    }
};