class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        //always think of edge case
        if(n==1)
            return nums[0];
        vector<int>v(n,-1);
        v[0]=nums[0];
        v[1]=max(nums[0],nums[1]);
        for(int i=2; i<n; i++){
            v[i] = max(v[i-1],(nums[i]+v[i-2]));
        }
        return v[n-1];
        
    }
};