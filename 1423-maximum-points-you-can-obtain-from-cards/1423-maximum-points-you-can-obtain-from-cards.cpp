class Solution {
public:
    int maxScore(vector<int>& c, int k) {
        
        long sum = 0;
        long mn = LONG_MAX;
        int n = c.size();
        for(int i=0; i<n; i++)
            sum+=c[i];
        if(k==n)
            return sum;
        int  i=0; 
        int  j=0;
        long s=0;
        while(j<n){
           
            if(j-i+1<n-k+1){
                 s+=c[j];
                 j++;
            }
               
               
            else{
                mn= min(mn,s);
                s-=c[i++];
                
            }
            
            
            
        }
          mn= min(mn,s);
        
        return sum - mn;
        
    }
};