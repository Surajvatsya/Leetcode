class Solution {
public:
    int minAddToMakeValid(string s) {
       stack<char>st;
        for(int i=0; i<s.length(); i++){
            
            if(s[i]=='('){
                st.push(s[i]);
            }
            
           else{
                if(!st.empty() and st.top()=='(')
                    st.pop();
               
                //always rem in stack qn
                //what if closing bracket comes and your stack is empty
                else
                {
                     st.push(s[i]);
                   
                }
            }
           
        }
         return st.size();
    }
};