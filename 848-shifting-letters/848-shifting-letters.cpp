class Solution
{
    public:
        string shiftingLetters(string s, vector<int> &v)
        {
            vector<long long> shifts ;
            for(auto &x : v)
                shifts.push_back(x);

            for (int i = shifts.size() - 2; i >= 0; i--)
            {
                shifts[i] += shifts[i + 1];
            }

            for (int i = 0; i < s.size(); i++)
            {
                long long  asc = (int) s[i] - 96;

                asc += shifts[i];
                int mod = asc % 26;
                if (mod == 0)
                    s[i] = 'z';
                else
                    s[i] = 96 + mod;
            }
            return s;
        }
};