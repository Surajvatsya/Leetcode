class Solution {
public:
    
    int reversed_no(int n){
        long ans = 0;
        
        while(n){
            // //if n<0 to v run krega
            //  if(ans>INT_MAX/10 or ans< INT_MIN/10)
            // b/c ans*10>INT_MAX/10 *10 or ans*10< INT_MIN/10 *10
            //   return 0;
            
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