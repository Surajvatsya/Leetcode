class Solution {
public:
    int climbStairs(int n) {
        int x = 1;
        int y = 2;
        
        if(n<=2)
            return n;
        
         int temp;
        for(int i=3; i<n+1; i++){
         temp   = x+y;
            x = y;
            y = temp;
            
        }
        return temp;
        
    }
};
