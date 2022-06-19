class Solution {
public:
    // unordered_map<string,vector<string>>mp;
    vector<vector<string>> suggestedProducts(vector<string>& p, string sw) {
        vector<vector<string>>ans;
        string s = "";
        for(int i=0; i<sw.size(); i++){
            s+=sw[i];
            int n = s.size();
            vector<string>v;
            for(int k=0; k<p.size(); k++){
                string temp = p[k];
                int tempsize = temp.size();
                if(n<=tempsize){
                    string q = temp.substr(0,n);
                    if(q==s)
                        v.push_back(temp);
                }
            }
            sort(v.begin(),v.end());
            
            if(v.size()>3){
                while(v.size()!=3)
                    v.pop_back();
            }
           ans.push_back(v); 
            
        }
        return ans;
    }
};