class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>ans;
        int prev = -1;
        unordered_map<char,int>mp;
        for(int i = 0;i<s.length();i++){
            mp[s[i]]=i;
        }
        int mx = mp[s[0]];
        for(int i = 0;i<s.length();i++){
            mx = max(mx,mp[s[i]]);
            if(mx==i)
            {
                ans.push_back(mx-prev);
                prev = mx;
            }     
        }
        return ans;
    }
};