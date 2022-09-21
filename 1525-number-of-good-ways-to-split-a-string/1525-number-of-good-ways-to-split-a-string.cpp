class Solution
{
    public:

        int numSplits(string s)
        {

            int n = s.size();
            int count = 0;
           

            unordered_set<char> l1;
            unordered_set<char> r1;

            vector<int> v1(n);
            vector<int> v2(n);
            

            for (int k = 0; k < n; k++)
            {
                 l1.insert(s[k]);
                r1.insert(s[n-1-k]);
                v1[k]=l1.size();
                v2[n-1-k]=r1.size();
                
            }

            
            for (int k = 0; k < n-1 ; k++)
            {
                count+= v1[k]==v2[k+1];
            }
            return count;
        }
};