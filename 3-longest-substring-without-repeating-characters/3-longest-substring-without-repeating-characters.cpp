class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        
        int n= s.length();
        
        unordered_map<char,int>mp;
        
        int i=0, j=0, count=0,ans =0;
        
        while(j<n){
            
            char m = s[j];
            
            mp[m]++;
            
            if(j-i+1==mp.size())
            {
                ans = max(ans, j-i+1);
                 j++;
                
            }
            else {
                
                            while(j-i+1 > mp.size()){

                            mp[s[i]]--;
                            if(mp[s[i]]==0)
                                mp.erase(s[i]);
                            i++;

                        }
                j++;
            }
            
        }
         if(mp.size()>ans)
                  ans = mp.size();
        return ans;
        
    }
};