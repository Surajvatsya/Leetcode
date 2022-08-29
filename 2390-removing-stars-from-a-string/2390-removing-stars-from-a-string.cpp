class Solution {
public:
    string removeStars(string s) {
     string ans = "";
        for(auto &x : s){
            if(x!='*')
              ans+=x;
            else{
                ans.erase(ans.begin()+ans.size()-1);
            }
        }
            return ans;
    }
};