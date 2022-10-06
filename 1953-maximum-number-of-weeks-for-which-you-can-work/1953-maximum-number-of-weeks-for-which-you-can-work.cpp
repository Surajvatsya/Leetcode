class Solution {
public:
    long long numberOfWeeks(vector<int>& m) {
        long long sum = 0;
       long long mx = 0;
        
        
        for(auto &x : m)
        {
             sum+=x;
           if(mx<x)
               mx=x;
        }
        
        long long rest = sum-mx;
        
        return min(2*rest + 1, sum);
        
    }
};