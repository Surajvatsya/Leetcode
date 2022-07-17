class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int>ans;
        int n = nums.size();
        int m = queries.size();
        for(int i=0; i<m; i++){
            vector<pair<string,int>>v;
            
            for(int j=0; j<n; j++){
                
                int sz = nums[j].size();
                
                string trimmed = nums[j].substr( sz-queries[i][1], queries[i][1]);
                                               
                v.push_back( { trimmed, j } );
                
            }
            
            sort(v.begin(), v.end());
            ans.push_back(v[queries[i][0]-1].second);
        }
        
        return ans;
    }
};