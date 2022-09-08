#define debug(x) cout<<#x<<" = "<<x<<endl;
class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        
        //all star ka left me kon sa candle h and right me kon sa h dekh jakr
        
        int n = s.size();
         vector<int>pre_sum(n);
        
        vector<int>left(n);
        int prev = -1;
        for(int i=0; i<n; i++){
            
            if(s[i] == '*'  ){
                left[i] = prev;
            }
            else
            {
                 prev = i;
                left[i] = prev;
            }
    }
        
        
        vector<int>right(n);
         prev = -1;
        for(int i=n-1; i>=0; i--){
            
            if(s[i] == '*'  ){
                right[i] = prev;
            }
            else
            {
                 prev = i;
                 right[i] = prev;
            }
    }
       
        prev=0;
        for(int i=0; i<n; i++){
            if(s[i]=='*')
            {
                 pre_sum[i]=prev+1;
                prev = pre_sum[i];
            }
            else{
                 pre_sum[i]=prev;
            }
        }
        
        
        vector<int>ans;
        for(auto &x : queries){
           
            int count=0;
            int l = x[0];
            int r = x[1];
             int a = right[l];
            
            int b = left[r];
            
            
            count+= a<=r and b>=l ? pre_sum[b]-pre_sum[a] : 0;
            
            
            
            ans.push_back(count);   
        }
        
        // return count;
        
//         left
//         0 0  -1 2 2 -1 5 5 5 -1
//         0 1   2 3 4  5 6 7 8 9 
            
//          right
//         2 2 -1 5 5-1 9 9 9 -1
//         0 1  2 3 4 5 6 7 8 9 
            
        return ans;
            
    }
};