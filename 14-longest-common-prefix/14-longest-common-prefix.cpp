class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        sort(s.begin(),s.end());
        int i=0; int j=0;
        int k = s.size();
        int n = s[0].size();
        int m = s[k-1].size();
        string ans="";
        while(i<n and j<m){
            if(s[0][i]==s[k-1][j])
                ans+=s[0][i];
            else
                break;
            i++;
            j++;
        }
        return ans;
    }
};