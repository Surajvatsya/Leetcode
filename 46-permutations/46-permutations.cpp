class Solution {
public:
   void  find_permute(vector<int>& nums,  vector<vector<int>>& ans,int l,int r){
         
       //base case
       if(l==r){
           ans.push_back(nums);
           return;
       }
       
       
       for(int i=l; i<=r; i++){
           //do
           swap(nums[l], nums[i]);
           
           //recur
            find_permute(nums,ans,l+1,r);
           
           
           //undo
            swap(nums[i], nums[l]);
       }
       
     }
    
    
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        int l=0; 
        int r = nums.size()-1;
         vector<vector<int>> ans;
         find_permute(nums,ans,l,r);
        return ans;
    }
};