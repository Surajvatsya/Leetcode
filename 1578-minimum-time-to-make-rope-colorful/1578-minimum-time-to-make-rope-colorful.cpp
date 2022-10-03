class Solution
{
    public:
        int minCost(string colors, vector<int> &t)
        {
             int n = colors.size();
            if(n==1)
                return 0;
            
           	//optimized
           
            int mx_t = 0;
            int s = 0;
            int ans = 0;
            for (int i = 0; i < n; i++)
            {
                if (i > 0 and  colors[i] !=  colors[i - 1]) {
                    ans+=s-mx_t;
                    s=0;
                    mx_t=0;
                }
                
                    mx_t=max(mx_t, t[i]);
                    s+=t[i];
                
            }
            
              ans+=s-mx_t;
            
            return ans;
        }
};