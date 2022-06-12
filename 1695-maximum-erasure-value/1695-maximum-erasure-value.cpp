class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) 
    {
        int l=0, r=0; //define left and right pointers for sliding windows approach
        
        vector<int> sum_arr; //sum_arr stores sum of element of nums at index i;
        sum_arr.push_back(0); //initially l and r at 0 so to consider element at index 0 we need to take 0 at index 0
        
        int sum=0, score=nums[0];
        for(auto it:nums) //storing sum into sum_arr
        {
            sum += it;
            sum_arr.push_back(sum);
        }
        
        unordered_map<int, int> mp; //stores element and their index
        
        while(r<nums.size()) //iterate till r pointer is lesser than nums' size 
        {
            if(mp.find(nums[r]) != mp.end()) l=max(l, mp[nums[r]]+1); //when repeated element come we move left pointer of the right of repeated element
            mp[nums[r]] = r; //assigning index to the element
            score = max(score, sum_arr[r+1]-sum_arr[l]); //get max score
            r++; //move r by 1 
        }
        return score;
        
    }
};