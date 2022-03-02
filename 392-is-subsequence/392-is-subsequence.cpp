class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.length();
        int n = t.length();
        if(m>n)
            return false;
        
        int i=0; int j = 0;
        while(i<m and j<n){
            
            if(i==m )
                return true;
            
            if(s[i]==t[j]){
                i++;j++;
            }
            else
                j++;
        }
        if(i==m)
            return true;
        return false;
            
        
        
    }
};