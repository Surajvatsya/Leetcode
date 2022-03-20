class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool inc=true;
        bool dec=true;
        int n = nums.size();
        for(int i=0; i<n-1;i++){
            if(nums[i+1] < nums[i]) inc=false;
             if(nums[i+1] > nums[i]) dec=false;
            if(inc==false and dec==false)
                return false;
        }
        return true;
        
    }
};