class Solution {
public:
    
    void permute(int l, int r, vector<int>&nums,map<vector<int>, int>&mp  ){
        if(l==r){
            mp[nums]=1;
            return ;
        }
        
        for(int i=l; i<=r; i++){
           
         //do
          swap(nums[l],nums[i]);
            
        //recurr
         permute(l+1,r,nums, mp);
            
        //undo
            swap(nums[i],nums[l]);
        }
        
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        map<vector<int>, int>mp;
        int l = 0;
        int r = nums.size()-1;
        permute(l,r,nums, mp);
        
        for(auto &x : mp){
            ans.push_back(x.first);
        }
        return ans;
        
    }
};