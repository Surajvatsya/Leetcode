class Solution {
public:
    int minSwaps(string s) {
        
        //open means matched
        int open = 0;
        
        //close means unmatched
        int close = 0;
        
        for(auto &x : s)
        {
            if(x=='['){
                open++;
            }
            else{
                if(open)
                    open--;
                else
                    close++;
            }
        }
        
        return (close + 1)/2;
        //pattern dekh le
        
        
    }
};