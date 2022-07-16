class Solution {
public:
    
    int count(int n){
        return __builtin_popcount(n);
    }
    
    vector<int> countBits(int n) {
         vector<int>v(n+1,0);
        for(int i=1; i<n+1; i++){
            v[i] = count(i);
        }
        return v;
    }
};