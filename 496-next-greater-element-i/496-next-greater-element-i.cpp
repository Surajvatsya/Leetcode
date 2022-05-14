class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        unordered_map<int,int>mp;
        
        for(int i=0; i<nums2.size(); i++){
            mp[nums2[i]]=i;
        }
        
        for(int i=0; i<nums1.size(); i++){
            
            int ind = mp[nums1[i]];
            int flag = 1;
            for(int j = ind+1; j<nums2.size(); j++){
                if(nums2[j]>nums1[i]){
                    ans.push_back(nums2[j]);
                    flag=0;
                    break;
                }
            }
            if(flag)
                ans.push_back(-1);
        }
        return ans;
    }
};