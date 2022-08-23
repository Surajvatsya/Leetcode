#define debug(x) cout<<#x<<" = "<<x<<endl;
class Solution {
public:
    
    
    
    string solve(long dec){
        string s  = "00000000000000000000000000000000";
            for (int pos = 31; pos >= 0; --pos)
            {
                if (dec % 2) 
                    s[pos] = '1';
                dec /= 2;
            }
        
        
                int flag = 1;
                for (int pos = 31; pos >= 0; --pos)
               {
                    if(flag == 0){
                        s[pos] = 1 xor s[pos];
                        continue;
                    }

                    if(s[pos]=='1'){
                        flag = 0;
                    }
            }
                return s;
        
    }
    
    
    string toHex(int n) {
        if(n==0)
            return "0";
        
        
        
        
        if(n<0){
            long x = (long) -1*n;
         string s =    solve(x);
            
        // unsigned long long int ulli2 = strtoull (s, 0, 16);    
            unsigned long long val = stoull(s, 0, 2);
        // debug(value);    
            string ans = "";
        while(val>0){
            
            unsigned long long  rem = val%16;
            if(rem==10)
                ans = 'a' + ans;
            
               else if(rem==11)
                ans = 'b' + ans;
             else if(rem==12)
                ans = 'c' + ans;
             else if(rem==13)
                ans = 'd' + ans;
            else  if(rem==14)
                ans = 'e' + ans;
           else if(rem==15)
                ans = 'f' + ans;
           
            else{
                ans =  to_string(rem) + ans;
            }
             val = val/16;
             
        }
        
        return ans;
           
        }
        
       
        string ans = "";
        while(n>0){
            
            long rem = n%16;
            if(rem==10)
                ans = 'a' + ans;
            
               else if(rem==11)
                ans = 'b' + ans;
             else if(rem==12)
                ans = 'c' + ans;
             else if(rem==13)
                ans = 'd' + ans;
            else  if(rem==14)
                ans = 'e' + ans;
           else if(rem==15)
                ans = 'f' + ans;
           
            else{
                ans =  to_string(rem) + ans;
            }
             n = n/16;
             
        }
        
        return ans;
    }
};