class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int>mp;
        int ans =0;
        for(auto &x :nums ){
            if(mp.find(x)!=mp.end())
                ans+=mp[x]++;
            else
                mp[x]++;
                
        }
        return ans;
        
    }
};