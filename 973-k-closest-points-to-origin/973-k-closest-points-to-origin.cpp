class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        vector<vector<int>>ans;
        
        //for making it T = Time complexity: O(N⋅logk) space complexity: O(k)
         priority_queue<pair<float,int>> pq;
        
        for(int i=0; i<points.size(); i++){
            int a = points[i][0];
            int b = points[i][1];
            float dis = sqrt(a*a + b*b);
            if(pq.size()<k)
           {
              
               pq.push({dis,i});
            }
            else if( pq.top().first>dis){
                 pq.pop();
                 pq.push({dis,i});
            }
            
        }
        
        for(int i=0; i<k; i++){
            pair<float,int> x = pq.top();
            pq.pop();
            ans.push_back(points[x.second]);
        }
        
        return ans;
    }
};