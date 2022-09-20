class Solution
{
    public:

       unsigned long long solve(string s)
        {

            int n = s.size();
        unsigned long long num = 0;
            for (int i = 0; i < n; i++)	//this what stoi built function do XD
            {
                num = num *10 + (s[i] - '0');
            }
            
            return num;
        }

    bool dfs(int ind, string prev, string s)
    {

       	//base case
        if (ind == s.size() and prev != s)
        {
            return true;
        }

        for (int k = ind; k < s.size(); k++)
        {

           	//curr string from idx to k

            string cs = s.substr(ind, k - ind + 1);
           	// cout<<cs<<endl;

           	//numeric value of prev
   unsigned long long n_prev;
            if (prev.size() != 0)
                n_prev = solve(prev);

      unsigned long long n_cs = solve(cs);

            if ((prev.size() == 0 or(n_prev - n_cs) == 1) and dfs(k + 1, cs, s))
            {
                return true;
            }
            
            
            // if( n_cs >  n_prev)
            // return false;
            
            
            if(n_cs > 1e17+1)
            return false;
            
        }

        return false;;
    }

    bool splitString(string s)
    {
        if (s.size() < 2)
            return false;
        string prev = "";
        return dfs(0, prev, s);
    }
};