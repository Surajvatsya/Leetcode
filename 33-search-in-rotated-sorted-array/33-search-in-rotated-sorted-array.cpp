class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int n=nums.size();
        int pivot;
        int s=0;
        int e = n-1;
        
        //find pivot
        
        while(s<=e){
            int m= e+(s-e)/2;
            if(nums[m]==target)
                return m;
           else if( nums[m]>=nums[s])
            {
                if(target<nums[m] and target>=nums[s])
                    e=m-1;
               else
                   s=m+1;
                
            }
            else {
                if(target<=nums[e] and target>nums[m])
                      s=m+1;
                else
                     e = m-1;
                 
            }
        }
        return -1;
        
    }
};