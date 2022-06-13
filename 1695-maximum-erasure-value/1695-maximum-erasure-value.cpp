class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int i=0;
        int j=0;
        int n = nums.size();
        int sum = 0;
        int mx = 0;
        unordered_map<int,int>mp;

        while(j<n){
            mp[nums[j]]++;
            sum+=nums[j];
            if(mp.size()==j-i+1)
            {
                mx=max(mx,sum);
            }
            else if(mp.size()<j-i+1) {
               
                        while(mp.size()!=j-i+1)
                        {
                                     sum-=nums[i];
                            
                                    mp[nums[i]]--;
                                    if(mp[nums[i]]==0)
                                        mp.erase(nums[i]);
                                    i++;

                         }
                   }
               j++;
              // mx=max(mx,sum);
                
              }

            return mx;
        }
};