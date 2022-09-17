class Solution {
public:
    string reverseWords(string s) {
       int i=0;
        while(s[i]==' ')
        {
           
             s.erase(s.begin());
           
        }
           
         i=s.size()-1;
        while(s[i]==' ')
        {
            s.erase(s.begin() + i);
             // cout<<s<<endl;  
            i--;
        }
        
       vector<string> v;
        string temp = "";
     
        for(auto &x : s){
            if(x!=' ')
            temp+=x;
            else{
                if(temp.size()>0)
                    v.push_back(temp);
                temp="";
            }
            
        }
         v.push_back(temp);
        reverse(v.begin(), v.end());
        string ans = "";
        
        for(auto &x : v)
            ans+=" "+x;
       ans.erase(ans.begin());
       
        return ans;
        
    }
};