class WordFilter {
public:
    unordered_map<string,int>mp;
    WordFilter(vector<string>& words) {
        
        int n = words.size();
        for(int i=0; i<n; i++){
            
            string word = words[i];
            int ws = word.size();
            for(int j=1; j<=ws; j++ ){
                string p = word.substr(0,j);
                for(int k=0; k<ws; k++){
                    string s = word.substr(k,ws);
                    string x = p+"@"+s;
                    mp[x]=i+1;
                }
            }
        }
        
        
    }
    
    int f(string p, string s) {
      string x = p+"@"+s;
        return mp[x]-1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */