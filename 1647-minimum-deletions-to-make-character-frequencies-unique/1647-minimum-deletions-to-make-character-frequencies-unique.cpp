class Solution {
public:
    int minDeletions(string s) {
        
        priority_queue<int>pq;
        unordered_map<char, int>mp;
        for(auto &x : s)
            mp[x]++;
        
        for(auto &x : mp)
            pq.push(x.second);
        
        int count = 0;
        //next ele se compare kr rh h so > 1
        while(pq.size() > 1){
            int topele = pq.top();
            pq.pop();
            
            if(pq.top()==topele){
                
                if(topele-1 > 0 ){
                     pq.push(topele - 1);
                    
                }
                    
               count++;
            }
            
        }
        
        return count;
        
    }
};

 //        b 4
 //        c 1
 //        a 1
 //        e 1
        