class Solution
{
    public:
        unordered_map<int, string> mp;
    vector<string> ans;

    void solve(string digits, int ind, int n, string s)
    {

       	//base case
        if (ind == n and s.size() == n)
        {
            ans.push_back(s);
            return;
        }

        for (int i = ind; i < n; i++)
        {
            int k = digits[i] - '0';
            for (auto &x: mp[k])
            {
                s += x;
               	// cout<<s<<endl;
                solve(digits, i + 1, n, s);
                s.pop_back();
            }
        }
    }

    vector<string> letterCombinations(string digits)
    {
        int n = digits.size();
        if (n == 0)
            return ans;
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";

        solve(digits, 0, n, "");
        return ans;
    }
};