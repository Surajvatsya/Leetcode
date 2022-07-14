class Solution {
public:
    
    int solve(vector<int>& nums, int i,  vector<int>&v){
        if(i>=nums.size())
            return 0;
        
        if(v[i]!=-1)
            return v[i];
        
        int b = INT_MIN;
        
        int a = nums[i] + solve(nums, i+2, v);
        
        if(i+1<nums.size())
         b = nums[i+1] + solve(nums, i+3, v);
       
        return v[i] = max(a,b);
       
    }
    
    int rob(vector<int>& nums) {
       
        int i=0;
        int n = nums.size();
        vector<int>v(n+1,-1);
     return   solve(nums, i, v);
        
    }
};