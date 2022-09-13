class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int s=0;
        int n= nums.size();
       int mx = 0;
        unordered_map<int,int>mp;
        for(int i=0; i<n; i++){
            if(nums[i]==0)
                nums[i]=-1;
            s+=nums[i];
            if(s==0){
                mx = max(mx, i+1);
            }
           else if(mp.find(s)!=mp.end()){
                int ans = i-mp[s];
                mx = max(mx,ans);
            }
            else{
                mp[s]=i;
            }
        }
        return mx;
    }
};