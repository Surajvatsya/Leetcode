class Solution {
public:
    int brokenCalc(int startValue, int target) {
        //in this type of qn try to come from target to startVal
        //2 operations on target as well
        //a>.target++
        //b>.target/=2
        //suppose target is odd then target/=2 will be fractional but we can't go to            any fractional step from startValue, if target is odd only target++
        
        //if target is even we can simply target/=2 to come to startValue asap.
        //what if target<startValue then only target++;
        int step = 0;
        while(target!=startValue){
            if(target<startValue){
                target++;
                step++;
            }
            else if(target%2==0){
            step++;
            target/=2;
        }
        else {
            step++;
            target++;
        }
        
        }
        return step;
            
    }
};