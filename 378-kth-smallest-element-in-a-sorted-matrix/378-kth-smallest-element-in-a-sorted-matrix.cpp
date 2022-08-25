class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        for(auto &x : matrix){
            for(auto &y : x){
                    
                if(pq.size()>= k and pq.top()>y)
                {
                    pq.pop();
                    pq.push(y);
                }
                else if(pq.size()<k)
                pq.push(y);
                
                
                
            }
        }
        
        return pq.top();
    }
};