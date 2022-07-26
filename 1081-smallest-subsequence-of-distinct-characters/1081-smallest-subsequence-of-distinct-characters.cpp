#define debug(x) cout<<#x<<" = "<<x<<endl;
class Solution {
public:
    string smallestSubsequence(string s) {
        
        //store frq
        vector<int>v(26,0);
        for(auto &x : s)
            v[x-'a']++;
        
        vector<bool>seen(26,false);
        stack<char>st;
        
        for(int i=0; i<s.length(); i++){
            if(st.empty())
            {
                 st.push(s[i]);
                // debug(s[i]);
                
                //frq dec
                v[s[i]-'a']--;
                
                //mark visit
                seen[s[i]-'a']=true;
                
                continue;
            }
            
            if(!seen[s[i]-'a'] ){
                
                if(s[i]>st.top())
                {
                     st.push(s[i]);
                      // debug(s[i]);
                    //dec freq
//                      v[s[i]-'a']--;
                    
                    //visit
                     seen[s[i]-'a']=true;
                }
                
                else{
                    
                    while(!st.empty() and s[i]<st.top() and v[st.top()-'a'] > 0  ){
                        
                        //unvisit
                         seen[ st.top()-'a']=false;
                          // debug(st.top());
                        //delete from ans string
                         st.pop();
                    }
                     // cout<<1;
                    //push curr char
                         st.push(s[i]);
                          
                          // debug(s[i]);
                        //dec freq
                     // v[s[i]-'a']--;
                    
                    //visit
                     seen[s[i]-'a']=true;
                         
                    
                }
           }
            v[s[i]-'a']--;
                    
            
        }
        string ans = "";
        while(!st.empty())
        {
            ans = st.top() + ans;
             
            st.pop();
        }
      
        return ans;
        
    }
};