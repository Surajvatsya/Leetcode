#define debug(x) cout<<#x<<" = "<<x<<endl;
class Solution
{
    public:
        int strStr(string hy, string ni)
        {
            int i = 0;
            int j = 0;
            int n = hy.size();
            int m = ni.size();
            while (j < n)
            {
                if (j - i + 1 < m)
                    j++;
                else if (j - i + 1 == m)
                {
                    string s = hy.substr(i, j + 1-i);
                    // debug(s);
                    if (s == ni)
                        return i;
                    i++;
                    j++;
                }
            }

            return -1;
        }
};