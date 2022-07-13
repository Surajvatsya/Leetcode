class Solution {
public:
    
    void solve(vector<int>op, vector<int> ip,int n, set<vector<int>>&s){
    if(ip.size()==0){
        sort(op.begin(),op.end());
        s.insert(op);
       return; 
    }
    
    vector<int>op1 = op;
    
    op1.push_back(ip[0]);
    ip.erase(ip.begin());
    
     solve(op1,ip,n,s);
     
     solve(op,ip,n,s);
    
    
}
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       vector<vector<int>>ans;
         vector<int> op ;
         set<vector<int>>s;
        int N = nums.size();
         solve(op,nums,N,s);
        for(auto &x : s)
            ans.push_back(x);
         return ans;
    }
};