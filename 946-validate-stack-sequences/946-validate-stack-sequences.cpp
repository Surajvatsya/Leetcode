class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        int n = pushed.size();
        int m = popped.size();
        int j=0;
        int i=0;
        stack<int>st;
        
        while(j<m and i<n){
            
            while(i<n and pushed[i]!=popped[j]){
                st.push(pushed[i]);
                i++;
               
            }
            
            i++;
            j++;
            
            
            //rem->st.top access must check !st.empty()
            //array element access must check j<m 
            while(j<m and !st.empty() and popped[j]==st.top()){
                st.pop();
                j++;
            }
            
        }
        
        return i==n and j==m;
    }
};