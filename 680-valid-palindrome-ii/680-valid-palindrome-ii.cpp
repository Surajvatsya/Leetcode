class Solution {
public:
    
    bool ispalindrome(string s,int i,int j){
        while(i<j){
            if(s[i++]!=s[j--])
                return false;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        int i=0;
        int j = s.length()-1;
       
        while(i<j){
            if( s[i]!=s[j]){
                if(ispalindrome(s,i+1,j) or ispalindrome(s,i,j-1))
                     return true;
                else
                    return false;
            }
               
            i++;
            j--;
        }
        
        return true;
    }
};