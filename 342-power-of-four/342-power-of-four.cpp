class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0)
            return false;
        
        double a = log(n)/log(4);
        
        
       if( a ==  (int) a )
            return true;
        
        return false; 
    }
};