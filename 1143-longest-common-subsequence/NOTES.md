else
s1 = solve( t1,  t2, n, m-1);
if(t[n-1][m]!=-1)
s2 = t[n-1][m];
else
s2 = solve( t1,  t2, n-1, m);
return t[n][m] =  max(s1,s2 );
}
}
int longestCommonSubsequence(string t1, string t2) {
​
int n = t1.size();
int m = t2.size();
return solve(t1,t2,n,m);
}
};
```