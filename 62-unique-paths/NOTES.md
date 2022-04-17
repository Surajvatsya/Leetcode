```
class Solution {
public:
int ans = 0;
int uniquePaths(int m, int n) {
//brute force recursive
int i=0;
int j = 0;
vector<vector<int>>dp(m,vector<int>(n,-1));
solve(i,j,m,n, dp);
return ans;
}
void solve(int i, int j, int m , int n, vector<vector<int>>&dp){
if(i==m-1 and j ==n-1)
{
ans++;
return;
}
if(dp[i][j]!=-1) return dp[i][j];
if(i+1<m)
solve(i+1,j,m,n);
if(j+1<n)
solve(i,j+1,m,n);
}
};
```