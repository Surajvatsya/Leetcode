class Solution {
public:
    
     vector<vector<int>>ans;
    
    void permute(vector<int>& nums, int l, int r){
        if(l==r)
        {
            ans.push_back(nums);
            return ;
        }
        
        for(int i=l; i<=r; i++){
        //do
        swap(nums[l], nums[i]);
        
        //reccur
        permute(nums, l+1,r);
        
        //undo 
            swap(nums[i], nums[l]);
        }
        
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
       
        int l = 0;
        int r = nums.size()-1;
        permute(nums,l,r);
        return ans;
    }
};