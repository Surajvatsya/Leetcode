class Solution {
public:
    bool isValid(string s) {
        
        stack<char>st;
        if(s.length()%2!=0)
            return 0;
       for(int i = 0;i<s.length();i++)
       {
           
           if(s[i]=='{' or s[i]=='[' or s[i]=='(')
           {
               st.push(s[i]);
           }
           
           else if(st.empty())
               return false;
           
          else if(s[i]=='}')
           {
               if(st.top()!='{' )
                   return false;
               st.pop();
           }
           else if(s[i]==']' )
           {
               if(st.top()!='[' )
                   return false;
               st.pop();
           }
           else if(s[i]==')' )
           {
               if(st.top()!='(')
                   return false;
               st.pop();
           }
       }
        return st.empty();
    }
};