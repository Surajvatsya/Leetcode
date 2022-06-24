class Solution {
public:
    bool canJump(vector<int>& nums) {
         int n = nums.size();
        int curr = 0;
        int Indexcango=0;
        for(int i=curr; i<= Indexcango ; i++){
            if(i>=n-1)
                return true;
            Indexcango = max(Indexcango, i+nums[i] );
        }
        return false;
    }
};