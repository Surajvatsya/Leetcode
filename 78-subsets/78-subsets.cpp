class Solution {
public:
   void solve(vector<int>ip, vector<int>op,  vector<vector<int>> &ans){
        vector<int> op1;
        if(ip.size()==0){
            ans.push_back(op);
            return;
        }
        
        op1 = op;
      
        op1.push_back(ip[0]);
        ip.erase(ip.begin()+0);
        solve(ip, op1,ans);
        solve(ip,op, ans);
    }
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>  ans;
        vector<int>op;
        solve(nums,op,ans);
        
        return ans;
        
    }
     
};