class Solution {
public:
    //practical copy page no 20
    //thora iterative socho
  
   
    int helper(int n){
        //no next move if you got n==1
        if(n==1)
            return 0;
        
        //explore all possiblities until n unless we dont get any no where that                     player           is winning
        for(int i=1; i<n and n%i==0; i++){
            if(helper(n-i)==0)
                //it means helper(i) is the winner bcs helper(i-1) can't  next move
               return 1;
        }
        
        
        //from 1 to n if I dont have any possiblities where helper(i-1)==0 it means                 helper(i)->player 1 is not winning helper(i-1) is winning
        return 0;
        
    }
    
    bool divisorGame(int n) {
       if(helper(n))
           return true;
        return false;
    }
};