class Solution {
public:
    //based on subset sum partition
    //sum of element would be integr in both the sets
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto &x : nums)
            sum+=x;
        if(sum%2!=0)
            return false;
        int s=sum/2;
        int n = nums.size();
        bool t[n+1][s+1];
        for(int i=0; i<n+1; i++){
            for(int j=0; j<s+1; j++){
                if(i==0)
                    t[i][j]=false;
                if(j==0)
                    t[i][j]=true;
                
            }
        }
        for(int i=1; i<n+1; i++){
            for(int j=1; j<s+1; j++){
                if(nums[i-1]<=j)
                t[i][j] = t[i-1][j-nums[i-1]] or t[i-1][j];
                else
                    t[i][j]=t[i-1][j];
                
            }
        }
        return t[n][s];
    }
};