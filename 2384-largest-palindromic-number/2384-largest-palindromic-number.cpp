class Solution {
public:
    string largestPalindromic(string num) {
        
       
        vector<int>v(10);
        for(auto &x : num)
            v[x-'0']++;
        
        string l="";
        
        for(int i=9; i>=0; i--){
            int frq = v[i];
            int t = frq/2;
            int ele=i;
            while(t--)
                l+=ele+'0';
            
            v[i]-=(frq/2)*2;
        }
        int sz = l.size();
        while(l[0]=='0')
        {
            l.erase(l.begin());
            sz--;
        }
        
         string r = l;
        reverse(r.begin(), r.end());
        
       
        
        int mid = -1;
        for(int i=9; i>=0; i--){
            if(v[i]>0)
            {
                 mid=i;
                break;
            }
        }
       
        if(mid!=-1)
            l+=mid+'0';
        
        // cout<<l;
        string ans = l+r;
        
        if(sz==0 and ans.size()==0)
            return "0";
        
        return ans;
        
            
            
        
    }
};

