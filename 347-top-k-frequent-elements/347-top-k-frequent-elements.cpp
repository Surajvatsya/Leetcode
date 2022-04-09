
class Solution {
public:
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mp;
        vector<int>v;
        for(int i = 0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>>pq;
        for(auto x: mp){
            pq.push({x.second,x.first});
        }
      for(int i = 0;i<k;i++){
          pair<int,int> ele = pq.top();
          pq.pop();
          v.push_back(ele.second);
      }
        return v;
    }
};