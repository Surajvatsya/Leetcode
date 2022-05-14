class Solution {
public:
    bool isValid(string s) {
        stack<char> c;
        for(int i=0; i<s.size(); i++){
            
            if(s[i]=='{' or s[i]=='(' or  s[i]=='['){
                c.push(s[i]);
            }
            
            //think about } / )  / ] these test cases if closing comes first st empty h so if st is empty we cant access its top value so
            
          else  if(c.empty())
                return false;
            
            if(s[i]=='}'){
                if(c.top()!='{')
                    return false;
                   c.pop(); 
            }
             if(s[i]==')'){
                if(c.top()!='(')
                    return false;
                     c.pop(); 
            }
             if(s[i]==']'){
                if(c.top()!='[')
                    return false;
                    c.pop();  
            }
            
        }
       return c.empty(); 
    }
};