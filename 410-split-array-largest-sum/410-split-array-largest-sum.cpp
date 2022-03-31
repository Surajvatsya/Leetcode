class Solution {
public:
    
    bool isvalid(vector<int>& nums, int m, int mid){
        
        int split = 1;
        int s=0;
        for(int i=0; i<nums.size(); i++){
            s+=nums[i];
            if(s>mid)
            {
                 split++;
                s=nums[i];
            }
            if(split>m)
                return false;
        }
        return true;
        
    }
    
    int splitArray(vector<int>& nums, int m) {
        if(m>nums.size())
            return -1;
        long s=0;
        int mx = INT_MIN;
        for(int i=0; i<nums.size(); i++){
             s+=nums[i];
            mx = max(mx,nums[i]);
        }
           
      int l = mx;
        int r = s;
        int ans=-1;
        while(l<=r){
           
            int mid = l+(r-l)/2;
            if(isvalid(nums,m,mid)){
                ans = mid;
                r = mid-1;
            }
            else
                l = mid+1;
        }
        return ans;
        
    }
};