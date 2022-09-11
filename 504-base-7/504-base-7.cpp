class Solution {
public:
    string convertToBase7(int num) {
        string ans = "";
        if(num==0)
            return "0";
        int f=0;
        if(num<0){
           f=1;
            num*=-1;
        }
        while(num){
            ans=to_string(num%7) + ans ;
            num/=7;
        }
        // reverse()
        return f ? '-'+ ans : ans;
    }
};