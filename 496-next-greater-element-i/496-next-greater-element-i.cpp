class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //map ka space complexcity = O(N)
        // Islye make shorter array map
         vector<int> ans(nums1.size(),-1);
        unordered_map<int,int>mp;
        
        for(int i=0; i<nums1.size(); i++){
            mp[nums1[i]]=i;
            
        }
        stack<int>st;
        
        for(int i=0; i<nums2.size(); i++){
            
            if(mp.find(nums2[i])!=mp.end()){
                
                if(st.empty() or  st.top()>nums2[i])
                    st.push(nums2[i]);
                
                else{
                     while(!st.empty() and st.top()<nums2[i]){
                        ans[mp[st.top()]]=nums2[i];
                        st.pop();
                        }
                st.push(nums2[i]);
              }
            }
            else{
                while(!st.empty() and st.top()<nums2[i]){
                    ans[mp[st.top()]]=nums2[i];
                    st.pop();    
                    }
            }
            
        }
        return ans;
        
    }
};