class Solution {
public:
    
    int reversed_no(int n){
        long ans = 0;
        
        while(n){
            
            
            
            int temp = n%10;
 
            ans = (ans*10) + temp;
            
            if(ans>INT_MAX or ans< INT_MIN)
              return 0;
 
            n = n/10;
        }
        
       
        return ans;
    }
    
    
    int reverse(int x) {
       return    reversed_no(x);
       
    }
};