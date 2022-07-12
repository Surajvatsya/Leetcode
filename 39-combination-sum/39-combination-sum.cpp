class Solution {
public:
    
    void solve(int i, vector<int>& c,  vector<int>v,vector<vector<int>> &ans, int target){
        //base case
         if(i>=c.size()){
            return;      
        }
        if(target<0)
            return;
        if(target==0){
            ans.push_back(v);
            return;
        }
            
        
       
        
        //pick
        v.push_back(c[i]);
        target-=c[i];
         solve(i, c, v, ans, target);
        // solve(i+1, c, v, ans, target);
        
        v.pop_back();
        target+=c[i];
         solve(i+1, c, v, ans, target);
        //not pick
        
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
         vector<vector<int>> ans;
        vector<int>v;
        
        solve(0, candidates, v, ans, target);
        return ans;
    }
};