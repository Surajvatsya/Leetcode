class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n-1;
        
        if(n==1)
            return nums[0];
        
        while(l<=r){
            
            //suppose mid is odd
            int mid = l+ (r-l)/2 ;
            //left half
            if(nums[mid]==nums[mid^1])
                l = mid+1;
            else
                r = mid-1;
                
        }
        return nums[l];
    }
};