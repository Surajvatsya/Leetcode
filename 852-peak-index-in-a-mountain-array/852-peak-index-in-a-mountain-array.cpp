class Solution {
public:
    
    int solve (int l, int r, vector<int>& nums, int n){
        
        while(l<=r){
            int m = l+(r-l)/2;
            if(m>0 and m<n-1){
                if(nums[m]>nums[m+1] and nums[m]>nums[m-1])
                    return m;
                else if(nums[m]<nums[m+1])
                    l = m+1;
                else
                    r= m-1;
            }
            else if(m==0){
                if(nums[0]>nums[1])
                    return 0;
                else return 1;
                
            }
            else if(m==n-1){
                if(nums[n-1]>nums[n-2])
                    return n-1;
                else
                    return n-2;
            }
                
        }
        return -1;
    }
    
    
    int peakIndexInMountainArray(vector<int>& nums) {
        int n = nums.size();
        
      return  solve(0,n-1,nums,n);
        
        
   
    }
};