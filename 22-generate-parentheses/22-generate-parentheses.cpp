#define debug(x) cout<<#x<<" = "<<x<<endl;
class Solution {
public:
    int N;
    void solve( string t,  vector<string>&ans, int open, int close){
        if(open==N and close==N){
            ans.push_back(t);
            return;
        }
         // debug(t);
        //take
        if(open<=N){
            t+='(';
           
         solve(t,ans, open+1, close);
        }
        
        //not take
        if(open>close and close<=N){
            t.pop_back();
                t+=')';
            
         solve(t,ans,open,close+1);
        
        }
        
    }
    
    vector<string> generateParenthesis(int n) {
       vector<string>ans;
        string t="";
        N=n;
        t+='(';
        int open = 1;
      int  close = 0;
        solve(t,ans, open, close);
        return ans;
    }
};