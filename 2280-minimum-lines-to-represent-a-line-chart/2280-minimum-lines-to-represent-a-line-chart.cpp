#define debug(x) cout<<#x<<" = "<<x<<endl;
class Solution {
public:
    
    int minimumLines(vector<vector<int>>& s) {
        int n = s.size();
       
        if(n==1)
            return 0;
        if(n==2)
            return 1;
        
        
        sort(s.begin(),s.end());
        
       
        
        int count=1;
       
           long double y = s[0][1] - s[1][1];
           long  double x =  s[0][0] - s[1][0];
           long  double m = y/x;
       
         
                  
        for(int i=1; i<n-1; i++){
           long    double y1 = s[i][1] - s[i+1][1];
           long    double x1 =  s[i][0] - s[i+1][0];
           long    double m1 = y1/x1;
         
           
            if(m1!=m){
                m=m1;
                count++;
               
            }
            
            
        }
        return count;
    }
};