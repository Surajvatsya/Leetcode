class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        
        unordered_map<int,int> mp;
        
        //store freq
        for(auto &x : tasks){
            mp[x]++;
        }
        
        int count = 0;
        
        for(auto &x : mp){
            int freq = x.second;
           if(freq==1)
               return -1;
                count+=(freq+2)/3;
             //10
        }
        
        return count;
    }
};