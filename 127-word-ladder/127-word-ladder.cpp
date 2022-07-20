class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
       
        unordered_map<string,int>mp;
        
        for(int i=0; i<wordList.size(); i++){
            mp[wordList[i]]=1;
        }
        
        if(mp.find(endWord)==mp.end())
            return 0;
        
        queue<string>q;
        
        q.push(beginWord);
        int depth = 0;
        int qsize = 0;
        int len = beginWord.length();
        
        while(!q.empty()){
            depth++;
            qsize = q.size();
            
            while(qsize--){
                 string original = q.front();
                 q.pop();
               
                    for(int j=0; j<len; j++){
                         string ele = original;
                        
                        for(int i=0; i<26; i++){
                            char ch = ele[j];
                            ele[j] = 97+i;
                                if(ele[j]!=ch){
                                    if(ele == endWord)
                                        return depth+1;
                                    if(mp.find(ele)!=mp.end())
                                    {
                                         q.push(ele);
                                          mp.erase(ele);
                                    }
                                  }

                            }    
                      }
            }
           
        }
        return 0;
        
    }
};