class Solution {
public:
    
   string reverseParentheses(string s) {
       
        string ans = "";
        int n = s.size();
       
        stack<int>st;
       
        for(int i=0; i<n; i++){
            
            if(s[i]=='(')
                st.push(i);
            
            else if(s[i]==')'){
                
                reverse(s.begin() + st.top() + 1, s.begin()+i);
                
                //ye last me hoga, st.pop()
                st.pop();
            }
            
        }
       
       
        
        for(int i=0; i<n; i++){
            
            if(s[i]=='(' or s[i]==')')
                continue;
            
            ans+=s[i];
        }
        
        return ans;
        
    }
};
