class Solution
{
    public:
       	// unordered_map<string, int> mp;
        long count = 0;
    int mod = 1000000007;
    bool valid(int i, int j)
    {
        return i >= 0 and i <= 3 and j >= 0 and j <= 2;
    }

    int solve(int row, int col, int n,  vector<vector<vector<int>>> &dp)
    {

       	

        if (n == 1)
        {

            return 1;
        }
        if (dp[n][row][col] != -1)
            return dp[n][row][col];
       

       	//go to 8 dirn
        int dx[] = { 1,
            1,
            -1,
            -1,
            2,
            2,
            -2,
            -2
        };
        int dy[] = { 2,
            -2,
            2,
            -2,
            1,
            -1,
            -1,
            1
        };

        long ans = 0;

        for (int i = 0; i < 8; i++)
        {
            int cx = row + dx[i];
            int cy = col + dy[i];
            if (cx == 3 and cy != 1)
                continue;

            if (valid(cx, cy))
            {

                ans = (ans + solve(cx, cy, n - 1, dp)) % mod;
            }
        }
        return dp[n][row][col] = ans % mod;
    }

    int knightDialer(int n)
    {
       	//2d vector
        vector<vector < int>> v(4, vector<int> (3, -1));
        int val = 1;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                v[i][j] = val++;
            }
        }
        v[3][1] = 0;

        // int dp[n + 1][4][4];
        // for (int i = 0; i < n + 1; i++)
        // {
        //     for (int j = 0; j < 4; j++)
        //     {
        //         for (int k = 0; k < 4; k++)
        //         {
        //             dp[i][j][k] = -1;
        //         }
        //     }
        // }
        
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(4, vector<int>(3,-1))); 
        
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (v[i][j] != -1)
                {

                    count = (count + solve(i, j, n, dp) % mod);
                }
            }
        }

        return count % mod;
    }
};