class Solution {
    
private:
    int solve(int i, int n, vector<int>&v){
        if(i==n)
            return 1;
        
        if(i>n)
            return 0;
        
        if(v[i]!=-1)
            return v[i];
        return v[i] = solve(i+1,n,v) + solve(i+2,n,v);
            
    }
    
public:
    int climbStairs(int n) {
        int i=0;
        vector<int>v(n+1, -1);
        return solve(i,n, v);
        
    }
};