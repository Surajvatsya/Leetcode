class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
       
         int n = garbage.size();
       
        unordered_map<char, int> mp;
         unordered_map<char, int> li;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<garbage[i].size(); j++)
            {
                mp[garbage[i][j]]++;
                 li[garbage[i][j]]= i;
            }
        }
        
        int ans = 0;
        // for(auto &x : mp)
        //     cout<<x.second<<endl;
        for(int i=0; i<n-1; i++){
            
                 for(auto &x : mp){
                     if(li[x.first]>i)
                          x.second+=travel[i];
                 }
            
        }
         // cout<<ans;
        
        for(auto &x : mp)
            ans+=x.second;
       
        return ans;
    }
};