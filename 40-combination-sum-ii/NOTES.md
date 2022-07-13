// cout<<2;
//pick
if(i>0 and v[i]!=v[i-1]){
v.push_back(c[i]);
solve(i+1,ans,v,c,t-c[i]);
}
//not pick
v.pop_back();
solve(i+1,ans,v,c,t);
}
vector<vector<int>> combinationSum2(vector<int>& c, int target) {
vector<vector<int>> ans;
vector<int>v;
solve(0,ans,v,c,target);
for(auto &x : mp)
ans.push_back(x.first);
return ans;
}
};
```
​
https://www.youtube.com/watch?v=G1fRTGRxXU8&t=464s
​