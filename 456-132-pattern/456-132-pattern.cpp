class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>mn(n);
        mn[0]=nums[0];
        int m = mn[0];
        
        for(int i=1; i<n; i++){
            if(nums[i]<m){
                m=nums[i];
                
            }
            mn[i]=m;
        }
        
        stack<int>st;
       
        
       for(int i=n-1; i>=0; i--){
        int x3 = nums[i];
           int x1 = mn[i];
          while(!st.empty() and st.top()<=x1 )
               st.pop();
           
             while(!st.empty() and st.top()<x3 and st.top()>x1)
              return true;
           
            
            
           st.push(nums[i]);
       }
        
        return false;
    }
};