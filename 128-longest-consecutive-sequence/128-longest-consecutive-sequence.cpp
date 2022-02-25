class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int n = nums.size();
        if(n==0)
            return 0;
        
        int mx=0;
        unordered_map<int,int> mp;
        
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }
        
        for(int i=0; i<n; i++){
            int count = 0;
            if(mp.find(nums[i]-1)==mp.end())
            {
                int k=0;
                while(1){
                    
                    if(mp.find(nums[i]+k)!=mp.end())
                    {
                        count++;
                        k++;
                    }
                    else
                    break;
                }
                mx = max(mx, count);
            }
               
        }
        return mx; 
    }
};