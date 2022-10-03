class Solution
{
    public:
        int minCost(string colors, vector<int> &t)
        {
            int ans = 0;
               int n = colors.size();
            
            if(n==1)
                return 0;
            
            priority_queue<int, vector < int>, greater < int>> pq;

            for (int i = 0; i < colors.size() - 1; i++)
            {
                if (colors[i] == colors[i + 1])
                {
                    pq.push(t[i]);
                }
                else
                {
                    pq.push(t[i]);
                    while (pq.size() > 1)
                    {
                        ans += pq.top();
                        pq.pop();
                    }
                    pq.pop();
                }
            }
         
            if (colors[n - 1] == colors[n - 2])
            {
                pq.push(t[n - 1]);
                while (pq.size() > 1)
                {
                    ans += pq.top();
                    pq.pop();
                }
            }
            return ans;
        }
};