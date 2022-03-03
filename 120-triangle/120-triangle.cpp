class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        int n = t.size();
        vector<int>v = t[n-1];
        for(int i= n-2; i>=0; i--){
            for(int j=0; j<t[i].size(); j++){
                v[j] = t[i][j] + min(v[j],v[j+1]); 
            }
        }
        return v[0];
        
    }
};