class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();
        vector<int>left(n,-1);
        vector<int>right(n,-1);
        int mn = INT_MAX;
        int mx = INT_MIN;
        
        for(int i=0; i<n; i++){
            mx = max(mx,nums[i]);
            left[i]=mx;
        }
        for(int i=n-1; i>=0; i--){
            mn = min(mn,nums[i]);
            right[i] = mn;
        }
        int sum = 0;
        for(int i=1; i<n-1; i++){
            int f1=1;
            int f2=1;
            if(nums[i]>=right[i+1] or nums[i]<=left[i-1])
                f1=0;
            if(!f1 and ( nums[i - 1] >= nums[i] or nums[i] >= nums[i + 1] ))
                f2=0;
            sum+= f1 ? 2 : f2 ? 1 : 0;
        }
        return sum;
    }
};