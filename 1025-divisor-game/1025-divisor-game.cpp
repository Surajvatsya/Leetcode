class Solution {
public:
    bool solve(int n, vector<int>&v){
        
        if(n==1)
            return false;
        
        if(v[n]!=-1)
            return v[n];
        
       
        
        for(int i=1; i*i<=n and  n%i == 0 ; i++){
            
           
                if(!divisorGame(n-i)){
                   return v[n] = true;
                }
                 if(i!=1 and !divisorGame(n-(n/i))){
                   return v[n-(n/i)] = true;
                }
                
                 
        }
        return v[n] = false;
        
    }
    
    
    bool divisorGame(int n) {
        vector<int>v(n+1,-1);
        
        return solve(n, v);
        
     
    }
};