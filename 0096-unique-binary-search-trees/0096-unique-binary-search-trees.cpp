class Solution {
public:
    int numTree(int n,  vector<int>&v){
         if(n<=1)
            return 1;
        if(v[n]!=-1)
            return v[n];
        int res = 0;
        for(int i=0; i<n; i++){
            res += numTree(i, v)*numTree(n-1-i, v);
        }
        return v[n] = res;
    }
  
    int numTrees(int n) {
        //catlan no
          vector<int>v(n+1, -1);
        
     return  numTree(n , v);
        
    }
};