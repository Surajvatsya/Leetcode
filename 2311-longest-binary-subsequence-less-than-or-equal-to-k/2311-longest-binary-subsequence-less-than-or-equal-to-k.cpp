#include <bits/stdc++.h>
#define debug(x) cout<<#x<<" = "<<x<<endl;
using namespace std;
class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.length()-1;
        long double val=0;
        int cnt=0;
        int flag = 1;
        for(int i=n; i>=0; i--){
            if(s[i]=='0')
            {
                cnt++;
               
                continue;
            }
            
            else if(flag){
                cnt++;
              
                 long double nv = pow(2,cnt-1);
                
                val+=nv;
                if(val>k)
                {
                      cnt--;
                    flag = 0;
                }
                
                
                
            }
                
               
        }
        return cnt;
    }
};