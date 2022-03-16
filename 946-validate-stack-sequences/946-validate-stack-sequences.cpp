class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>st;
        st.push(pushed[0]);
        int i=1;
        int n = pushed.size();
        
        while(!st.empty() or i<n){
          
            if(  !st.empty() and  st.top()==popped.front())
            {
                st.pop();
                popped.erase(popped.begin() + 0);
            }
             else if(i<n){
                    st.push(pushed[i]);
                    i++;
                }
             else if(st.top()!=popped.front())
                return false;
            }
        
            return true;
        }
        
    
};