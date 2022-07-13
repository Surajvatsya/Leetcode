class Solution {
public:

   

    void solve(int i, vector<vector<int>> &ans, vector<int> v,vector<int>& c,int t){

       
         if(t==0){
            ans.push_back(v);
            return;
        }

        if(t<0 or i>=c.size())
            return;

        for(int k=i; k<c.size(); k++)
        {
             if(k>i && c[k]==c[k-1])
                continue;
            
             if(c[k]<=t){
                 v.push_back(c[k]);
                 solve(k+1,ans,v,c,t-c[k]);
                 v.pop_back();
                
            }
             
        }
    }



    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        vector<vector<int>> ans;
        vector<int>v;
         sort(c.begin(), c.end());
        solve(0,ans,v,c,target);
       
        return ans;
    }
};