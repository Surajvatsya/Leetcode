class Solution {
public:
    
    bool sove(string s, string t, int m, int n){
        if(m==0)
            return true;
        if(n==0)
            return false;
        if(s[m-1]==t[n-1])
            return sove(s,t,m-1,n-1);
        
       return  sove(s,t,m,n-1);
        
        
    }
    
    
    bool isSubsequence(string s, string t) {
      
        int m = s.length();
        int n = t.length();
        if(m>n)
            return false;
        
        
        return sove(s,t,m,n);
    }
};