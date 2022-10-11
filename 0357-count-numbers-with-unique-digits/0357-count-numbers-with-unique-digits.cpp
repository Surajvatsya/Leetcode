class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0)
            return 1;
        
        //n==1
        int ans = 10;
        int choices = 9;
        int prod = 9;
        
        while(n-- > 1){
            prod*=choices--;
            ans+=(prod);
        }
        
        return ans;
        
        
    }
};