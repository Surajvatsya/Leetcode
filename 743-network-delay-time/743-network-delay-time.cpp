class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<pair<int,int>>g[n+1];
        
        for(int i=0; i<times.size(); i++){
           int u = times[i][0];
            int v = times[i][1];
            int wt = times[i][2];
            g[u].push_back({v,wt});
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        vector<int>dis(n+1, INT_MAX);
        pq.push({0,k});
        dis[k]=0;
        
        while(!pq.empty()){
            int curr_n = pq.top().second;
             int curr_d = pq.top().first;
            pq.pop();
            for(auto &x : g[curr_n]){
                int next_n = x.first;
                int next_d = x.second;
                
                if(dis[next_n]>curr_d + next_d){
                    dis[next_n]=curr_d + next_d;
                    pq.push({dis[next_n], next_n});
                }
                    
            }
        }
        int mx = INT_MIN;
        for(int i=1; i<n+1; i++){
            if(dis[i]==INT_MAX)
                return -1;
            mx = max(mx, dis[i]);
        }
        return mx;
    }
};