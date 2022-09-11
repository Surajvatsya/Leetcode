class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        
        //sort
        sort(intervals.begin(), intervals.end());
        
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        
        for(auto &x : intervals)
        {
            int start = x[0];
            int end = x[1];
            if(!pq.empty() and pq.top()<start){
                pq.pop();
            }
            pq.push(end);
        }
        
        return pq.size();
        
    }
};