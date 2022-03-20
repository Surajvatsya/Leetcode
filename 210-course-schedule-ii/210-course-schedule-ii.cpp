class Solution {
public:
    
   
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int N = numCourses;
        int n = prerequisites.size();
         vector<vector<int>>g(N);
        vector<int>in(N,0);
        for(int i=0; i<n; i++){
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            g[u].push_back(v);
            in[v]++;
        }
        
        
         vector<int>ans;
        
        queue<int>q;
        for(int i=0; i<N; i++){
            if(in[i]==0)
                q.push(i);
        }
       
        while(!q.empty()){
            
            int ele = q.front();
            ans.push_back(ele);
            q.pop();
            for(auto &x : g[ele])
            {
                 in[x]--;
                if(in[x]==0)
                    q.push(x);
            }
        }
        int sz = ans.size();
        if(sz==N)
        return ans;
        return {};

    }
};