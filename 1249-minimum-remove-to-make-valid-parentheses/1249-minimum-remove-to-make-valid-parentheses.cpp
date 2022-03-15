class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();
        stack<int>st;
        for(int i =0;i<s.length();i++){
            //yha par i<n ni likh skte ho bcs 
            //You are removing elements from list which changes the size. This will lead to                    accessing elements beyond your list.
            if(s[i]=='(')
                st.push(i);
            
            if(s[i]==')')
            {
                if(!st.empty())
                    st.pop();
                 else
                s.erase(s.begin()+i--);
                //why here i--
                //Input: s = "lee(t(c)o)de)"
                // Output: "lee(t(c)o)de"
                
            }
        }
    
        while(!st.empty()){
            //Input: s = "))(("
                //Output: ""
            s.erase(s.begin()+st.top());
            st.pop();
        }
        return s;
    }
        
};