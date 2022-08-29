class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> ans;
        
        //rem this step
        sort(nums.begin(), nums.end());
        
        for(auto &x : queries){
            int s=0;
            int count=0;
            for(auto &y : nums){
                s+=y;
               
                if(s>x)
                    break;
                 count++;
            }
            ans.push_back(count);
            
        }
        return ans;
    }
};