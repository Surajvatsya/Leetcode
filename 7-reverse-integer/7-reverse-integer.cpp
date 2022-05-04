class Solution {
public:
    
    int reversed_no(int n){
        long ans = 0;
        
        // Reverse Integer krna ho to yhi follow kro always
        
        while(n){
            
            // //if n<0 to v run krega
            //  if(ans>INT_MAX/10 or ans< INT_MIN/10)
            // b/c ans*10>INT_MAX/10 *10 or ans*10< INT_MIN/10 *10
            //   return 0;
            
            // NOTE :- -ve no k modulo v -ve hota h
            int temp = n%10;
            ans = (ans*10) + temp;
          
            //since yha ans*10 ho rha h so ans ko long me lye h
            
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