class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
     
        //heap
        priority_queue<pair<int,int>> pq;
        int n = costs.size();
        
        for(int i=0; i<n; i++){
            int diff = costs[i][1]-costs[i][0];
            pq.push({diff,i});
        }
        
       long ans = 0;
            
            for(int i=0; i<n/2; i++){
               pair<int,int>p = pq.top();
                pq.pop();
                int idx =p.second;
                ans+=costs[idx][0];
            }
            for(int i=n/2; i<n; i++){
                pair<int,int>p = pq.top();
                pq.pop();
                int idx =p.second;
                ans+=costs[idx][1];
            }
        
        
        return ans;
        
    }
};