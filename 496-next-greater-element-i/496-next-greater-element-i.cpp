class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
       
        
        //nums1 subset h, nums2 ka jitna v greater element h sabko nikal lo
        //nums1 me jiska jiska maang rha h sbke samne rakh dena 
        
        unordered_map<int,int> mp;
        stack<int>st;
        vector<int>ans(nums1.size(),-1);
        
        for(int i=0; i<nums2.size(); i++){
            
            while(!st.empty() and st.top()<nums2[i]){
                mp[st.top()] = nums2[i];
                st.pop();
            }
            
            st.push(nums2[i]);
        }
        
        for(int i=0; i<nums1.size(); i++){
            
            if(mp.find(nums1[i])!=mp.end()){
                ans[i]=mp[nums1[i]];
            }
        }
        
        return ans;
    }
};