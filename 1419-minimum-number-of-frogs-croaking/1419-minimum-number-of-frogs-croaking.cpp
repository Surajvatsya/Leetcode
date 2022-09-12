class Solution
{
    public:
        int minNumberOfFrogs(string croakOfFrogs)
        {
            int c = 0, r = 0, o = 0, a = 0, k = 0;
            int frog = 0;
            int mx = INT_MIN;
            for (auto &x: croakOfFrogs)
            {
                switch (x)
                {
                    case 'c':
                        c++;
                        frog++;
                        break;
                    case 'r':
                        r++;
                        break;
                    case 'o':
                        o++;
                        break;
                    case 'a':
                        a++;
                        break;

                    case 'k':
                        k++;
                        frog--;
                        break;
                }
                
                // "aoocrrackk"
                if(c<r or r<o or o<a or a<k)
                    return -1;
                
                mx = max(mx, frog);
            }

            int t = c;
            //croakc
            if (r != t or o != t or a != t or k != t)
                return -1;
            return mx;
        }
};