class Solution {
public:
    
int longestCommonSubsequence(string t1, string t2) {
       int  n = t1.size();
        int m = t2.size();
        string s="";
        int t[n+1][m+1];
        for(int i=0; i<n+1; i++){
            for(int j=0; j<m+1; j++){
                if(i==0 or j==0)
                    t[i][j]=0;
                
            }
        }
        
        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(t1[i-1]==t2[j-1])
                {
                    t[i][j]=1+t[i-1][j-1];
                }
                else
                     t[i][j]=max(t[i-1][j],t[i][j-1]);
                
            }
        }
        
        return t[n][m];
        
    }
    
    
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        int lcs = longestCommonSubsequence(word1,word2);
        int ans =0;
        ans+=(n-lcs) + (m-lcs);
        return ans;
    }
};