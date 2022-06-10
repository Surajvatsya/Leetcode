class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        int j=0;
        int n = s.size();
        unordered_map<int,int>mp;
        int mx = 0;
        int count = 0;
        while(j<n){
            mp[s[j]]++;
             count++;
            if(mp.size()==j-i+1)
            {
                 j++;
                
                mx=max(mx,count);
               
            }
            else{
                    while(mp.size()<j-i+1){
                                count--;
                                 mp[s[i]]--;

                                if(mp[s[i]]==0)
                                    mp.erase(s[i]);

                                  i++;

                        }
                j++;
            }
             mx=max(mx,count);
                
        }
        return mx;
    }
};