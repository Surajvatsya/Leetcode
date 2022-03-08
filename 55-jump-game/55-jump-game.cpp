class Solution {
public:
    bool canJump(vector<int>& nums) {
    //greedy algo
    //kis index tak jump kr skte h
    //concept -> index pe khela
    int can_jump = 0;
        int n = nums.size();
        for(int i=0; i<=can_jump; i++){
            if(i>=n-1)
                return true;
            can_jump = max(can_jump, i+nums[i]);
        }
        return false;
    }
};