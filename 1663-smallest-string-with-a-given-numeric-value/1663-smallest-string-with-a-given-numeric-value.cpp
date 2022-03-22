class Solution {
public:
    string getSmallestString(int n, int k) {
        
        string ans = "";
        for(int i=0; i<n; i++){
            ans+='a';
        }
        k-=n;
        while(k>0){
          ans[n-1]+=min(25,k);
            k-=min(25,k);
            n--;
            
        }
        return ans;
    }
};