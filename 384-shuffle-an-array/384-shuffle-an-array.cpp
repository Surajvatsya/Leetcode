class Solution
{
    public:
        vector<int> v;
    int n;
    Solution(vector<int> &nums)
    {
        v = nums;
        n = nums.size();
    }

    vector<int> reset()
    {
        
        return v;
    }

    vector<int> shuffle()
    {
        vector<int> temp = v;
        int i =  n - 1;
        
        
        while (i >0)
        {

             int j = rand() % (i+1);
             swap(temp[i], temp[j]);
             i--;
        }
       
        return temp;
    }
};

/**
 *Your Solution object will be instantiated and called as such:
 *Solution* obj = new Solution(nums);
 *vector<int> param_1 = obj->reset();
 *vector<int> param_2 = obj->shuffle();
 */