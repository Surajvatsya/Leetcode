class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j; 
        if(nums.size()<2)
            return nums.size();
       for(int i = 0;i<nums.size();i++){
            j = i+1;
            if(j<nums.size()){
                if(nums[i]==nums[j]){
               nums.erase(nums.begin()+j);
               i--;
           }
           } 
       } 
        return nums.size();
    }
};