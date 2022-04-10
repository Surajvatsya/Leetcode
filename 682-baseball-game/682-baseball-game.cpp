class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        for(int i=0; i<ops.size(); i++){
            if(ops[i]=="C"){
                st.pop();
            }else if(ops[i]=="D"){
                int x = st.top();
                st.push(2*x);
            }else if(ops[i]=="+"){
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                st.push(y);
                st.push(x);
                st.push(x+y);
            }else{
                st.push(stoi(ops[i]));
            }
        }
        
        int i =0;
        long s =0;
        while(!st.empty()){
            cout<<st.top()<<endl;
            s+=st.top();
            st.pop();
        }
        return s;
    }
};