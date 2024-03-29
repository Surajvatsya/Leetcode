class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
     
        map< vector<int>,vector<string> >mp;
        for(auto &x : strs){
            vector<int>v(26,0);
            for(auto &y : x){
                v[y-'a']++;
            }
            mp[v].push_back(x);
        }
            vector<vector<string>>s;
        for(auto &p : mp)
            s.push_back(p.second);
        return s;
    }
};