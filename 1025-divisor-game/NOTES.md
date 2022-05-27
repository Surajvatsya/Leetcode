if(a[n]!=-1)
return a[n];
//explore all possiblities until n unless we dont get any no where that                     player           is winning
for(int i=1; i<n and n%i==0; i++){
if(helper(n-i,a)==0)
//it means helper(i) is the winner bcs helper(i-1) can't  next move
return a[n-i]=1;
}
//from 1 to n if I dont have any possiblities where helper(i-1)==0 it means                 helper(i)->player 1 is not winning helper(i-1) is winning
return a[n]=0;
}
bool divisorGame(int n) {
int dp[1001];
// for(int i=0; i<1001; i++)
//     dp[i]=-1;
memset(dp,-1,sizeof(dp));
if(helper(n,dp))
return true;
return false;
}
};
```