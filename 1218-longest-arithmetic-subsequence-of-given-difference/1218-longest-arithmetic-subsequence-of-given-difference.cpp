class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n=arr.size();
        unordered_map<int,int>mp;
        int maxi=0;
        for(auto &it:arr){
            mp[it]=1+mp[it-difference];
            maxi=max(maxi,mp[it]);
        }
        return maxi;
    }
};