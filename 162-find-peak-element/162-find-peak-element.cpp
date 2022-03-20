class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        if(nums.size()==1)
            return 0;
        
        int low = 0;
        int high = nums.size()-1;
        int n = nums.size()-1;
        int idx=-1;
        while(low<=high){
            
            int mid = (high-low)/2 + low;
            if(mid>0 and mid<n){
                if(nums[mid]>nums[mid+1] and nums[mid]>nums[mid-1])
                {
                    idx=mid;
                    break;
                }
                else if(nums[mid+1]>nums[mid])
                    low = mid+1;
                else if(nums[mid-1]>nums[mid])
                    high = mid-1;
            }
            else if(mid==0){
                if(nums[mid+1]>nums[mid])
                {
                    idx= mid+1;
                    break;
                }
                else
                {
                    idx=mid;
                    break;
                }
            }
            else if(mid==n){
                if(nums[mid-1]>nums[mid])
                {
                    idx=mid-1;
                    break;
                }
                else
                {
                    idx=mid;
                    break;
                }
            }
        }
        return idx;
    }
};