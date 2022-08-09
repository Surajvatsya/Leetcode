class Solution {
public:
    int lastRemaining(int n) {
        if(n==1)
            return 1;
       
        
        int a = 1;
        int d = 1;
        int flag = 1;
        
        while(n>1){
            
             bool achange = false;
            
            if(n%2!=0 or flag)
            achange = true;
            
            
           
            if(achange)
                a+=d; // a = 2
            
             d*=2; //2    4
            
            n = n/2; //4   2
            
            flag = flag xor 1;
            
        }
        
        
        return a;
    }
};