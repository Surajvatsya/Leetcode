class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        int n = pushed.size();
       
        int j=0;
        int i=0;
        stack<int>st;
        
        while( i<n ){
            
            //jab v index ko access kr rha hai, make sure tm usko check krlo out of index na jaye. 
            
            while(i<n and pushed[i]!=popped[j]){
                st.push(pushed[i]);
                i++;
               
            }
            
            i++;
            j++;
            
            
            //rem->st.top access must check !st.empty()
            //array element access must check j<m 
            while(j<n and !st.empty() and popped[j]==st.top()){
                st.pop();
                j++;
            }
            
        }
        
        return i==n and j==n;
    }
};