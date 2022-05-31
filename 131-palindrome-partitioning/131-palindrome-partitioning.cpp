class Solution {
public:
    bool ispalindrome(string s, int i, int j){
        while(i<j){
            if(s[i++]!=s[j--])
                return false;
        }
        return true;
    }

    void solve(string s, int ind, vector<string>&path,  vector<vector<string>>&ans ){
        if(ind == s.size()){
            ans.push_back(path);
            return;
        }
        for(int i=ind; i<s.size(); i++){
            if(ispalindrome(s,ind,i)){
                path.push_back(s.substr(ind,i-ind+1));
                solve(s,i+1,path,ans);
                path.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string>path;
         vector<vector<string>>ans;
        //index ka khel h
        // 1 <= s.length <= 16 brte force chal jayga
        solve(s,0,path,ans);
        return ans;
    }
};