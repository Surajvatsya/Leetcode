```
class Solution {
public:
int maximumUniqueSubarray(vector<int>& nums) {
int i=0;
int j=0;
int n = nums.size();
long sum = 0;
long mx = 0;
unordered_map<int,int>mp;
while(j<n){
mp[nums[i]]++;
if(mp.size()==j-i+1)
{
sum+=nums[j];
j++;
}
else if(mp.size()<j-i+1) {
mx=max(mx,sum);
while(mp.size()!=j-i+1){
sum-=nums[i];
mp[nums[i]]--;
if(mp[nums[i]]==0)
mp.erase(nums[i]);
i++;
}
}
j++;
}
return mx;
}
};
```