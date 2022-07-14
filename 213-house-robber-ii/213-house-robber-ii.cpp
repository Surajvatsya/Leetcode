class Solution {
public:
    
    int solve(int i, vector<int>& nums, vector<int>&v ){
        
        if(i<0)
            return 0;
        
          if(v[i]!=-1)
              return v[i];
        
        int b = INT_MIN;
        int a = nums[i] + solve(i-2, nums, v);
        if(i-1>=0)
         b = nums[i-1] + solve(i-3, nums, v);
        // cout<<a<<" "<<b<<endl;
        return v[i] = max(a,b);
        
    }
    
    int rob(vector<int>& nums) {
        
        int n = nums.size();
         vector<int>v(n+1,-1);
        if(n==1){
            return  solve(n-1, nums, v);
        }
       
        int a = solve(n-2, nums, v);
        
        nums.erase(nums.begin());
           vector<int>v1(n+1,-1);
        n = nums.size();
        int b = solve(n-1, nums, v1);
        return max(a,b);
        
        
    }
};