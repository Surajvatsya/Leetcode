class Solution {
public:
    
    
    // if there is n* m then max no of int in ans = n+m
    // 9*9 = 81 / 2*3 = 06
    
    
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        
        
        //impo line
        vector<int> res(num1.size()+num2.size(), 0);
        
        for (int i = num1.size()-1; i >= 0; i--) {
            for (int j = num2.size()-1; j >= 0; j--) {
                res[i + j + 1] += (num1[i]-'0') * (num2[j]-'0');
                
                //beautiful line
                res[i + j] += res[i + j + 1] / 10;
                res[i + j + 1] %= 10;
            }
        }
        
        
        
        int i = 0;
        string ans = "";
        while (res[i] == 0) i++;
        while (i < res.size()) ans += to_string(res[i++]);
        
        return ans;
    }
};