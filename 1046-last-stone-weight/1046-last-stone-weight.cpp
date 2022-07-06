class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        int n = stones.size();
        if(n==1)
            return stones[0];
        
        for(int i=0; i<n; i++){
            pq.push(stones[i]);
        }
        
        while(pq.size()>1){
            // int flag = 0;
            int p = pq.top();
            pq.pop();
            int q;
            // if(pq.size()>0){
                 q = pq.top();
                pq.pop();
                // flag = 1;
            // }
            
            // if(flag) {
                if(p!=q)
                    pq.push(abs(p-q));
                // cout<< p-q <<endl;
                    
            // }
        }
        
        if(pq.size()==0)
            return 0;
        return pq.top();
    }
};