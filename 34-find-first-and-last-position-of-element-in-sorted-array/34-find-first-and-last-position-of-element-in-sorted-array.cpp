#define debug(x) cout<<#x<<" = "<<x<<endl;
class Solution {
public:
    
    void bs(vector<int>& nums, int target, int &mx, int &mn){
        int i=0;
        int j = nums.size()-1;
        
        while(i<=j){
            int mid = i+(j-i)/2;
            if(target==nums[mid]){
                int f = mid;
                // f++;
                // mn = min(mn, mid);
                // mx = max(mx, mid);
                while(mid>=0 and nums[mid]==target)
                {
                     mn = min(mn, mid);
                    // debug(mn);
                    mid=mid-1;
                }
                
                 while(f<nums.size() and nums[f]==target)
                 {
                      mx = max(mx, f);
                      // debug(mx);
                      f=f+1;
                 }
             return;   
            }
               else if(target>nums[mid])
                    i = mid+1;
                else if(target<nums[mid])
                    j = mid-1;
        } 
    }
    
    
    vector<int> searchRange(vector<int>& nums, int target) {
       int mx = INT_MIN;
        int mn = INT_MAX;
        bs(nums,target,mx,mn);
        if(mx==INT_MIN)
            return {-1,-1};
        return {mn, mx};
    }
};