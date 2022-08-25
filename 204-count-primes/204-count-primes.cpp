class Solution {
public:
    int countPrimes(int n) {
       //sieve of eratotstanes
        vector<int>v(n+1, 0);
        
        for(int i=2; i*i<n; i++){
            
                if(v[i]==0){
                    for(int j=i*i; j<n; j+=i){
                    if(v[j]!=1)
                        v[j]=1;
                }
            }
            
        }
        int count=0;
        for(int i=2; i<n; i++){
            if(v[i]==0)
                count++;
        }
        return count;
         
    }
};