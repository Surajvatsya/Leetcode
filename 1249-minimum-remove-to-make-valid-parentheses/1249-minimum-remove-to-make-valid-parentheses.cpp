class Solution {
public:
    string minRemoveToMakeValid(string s) {
         string ans = "";
        stack<int>st;
        
        for(int i=0; i<s.length(); i++){
           
            if(s[i]=='('){
               st.push(i); 
                 
            }
                
            else if(s[i]==')'){
                
                //rem for all concept in stack everytime
                
                //before that you have to check wheather st.top exist or not means its empty or not
                if( !st.empty() )
                {
                     st.pop();
                   
                }
                else
                {
                    //rem this step
                     s.erase(s.begin()+i); 
                    i--;
                    // cout<<s<<endl;
                   
                }
               
            }
             
        }
        
        
        while(!st.empty()){
            int i = st.top();
            
            st.pop();
           s[i]='*';
        }
        // cout<<s<<endl;
        for(auto &x : s )
            if(x!='*')
                ans+=x;
        
        return ans;
    }
};