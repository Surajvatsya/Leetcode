class Solution
{
    public:
        int count = 0;
    void find_permute(vector<int> &nums, vector<vector< int>> &ans, int l, int r)
    {

       	//base case
        if (l == nums.size())
        {

            count++;

            return;
        }

        for (int i = l; i <= r; i++)
        {
           	//do
            swap(nums[l], nums[i]);

           	//recur

            if (nums[l] % (l + 1) == 0 or(l + 1) % nums[l] == 0)

                find_permute(nums, ans, l + 1, r);

           	//undo
            swap(nums[i], nums[l]);
        }
    }

        vector<vector < int>> permute(vector<int> &nums)
        {
            int l = 0;
            int r = nums.size() - 1;
            vector<vector < int>> ans;
            find_permute(nums, ans, l, r);
            return ans;
        }

        int countArrangement(int n)
        {
            vector<int> v1(n);
            for (int i = 0; i < n; i++)
                v1[i] = i + 1;

           vector<vector < int>> p =  permute(v1);
                   
            return count;
        }
    };