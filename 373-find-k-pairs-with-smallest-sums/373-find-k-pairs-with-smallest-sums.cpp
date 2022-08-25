typedef pair<int, pair<int,int> > pi;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pi, vector<pi> > pq;
        vector<vector<int>> ans1;
        
        
        
        
        for(auto &x : nums1){
            for(auto &y : nums2){
                if(pq.size()<k){
                    pq.push({x+y,  {x,y} });
                }
                // pair<int, pair<int,int>> p = pq.top();
                else if(pq.top().first>x+y) {
                    
                    
                        pq.pop();
                        pq.push({x+y,  {x,y} });
                    
                }
                else
                    break;
            }
        }
        
        while(!pq.empty()){
            pair<int, pair<int,int> >p = pq.top();
            pq.pop();
            vector<int>ans;
            pair<int,int> p1 = p.second;
            ans.push_back(p1.first);
            ans.push_back(p1.second);
            ans1.push_back(ans);
            
        }
        return ans1;
    }
};