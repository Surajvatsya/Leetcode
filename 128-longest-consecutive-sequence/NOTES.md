https://www.youtube.com/watch?v=qgizvmgeyUM
**brute force**
​
```
class Solution {
public:
int longestConsecutive(vector<int>& nums) {
//brute
if(nums.size()==0)
return 0;
if(nums.size()==1)
return 1;
int n = nums.size();
int mx = 0;
int cnt = 0;
int flag = 0;
sort(nums.begin(),nums.end());
for(int i=0;i<n-1; i++){
if(nums[i]==nums[i+1])
continue;
if((nums[i]+1)==nums[i+1])
{
cnt++;
mx = max(cnt, mx);
flag = 1;
}
else
{
cnt = 0;
}
}
return  mx+1 ;
}
};
```