
class Solution {
 	public:
 		bool isBipartite(vector<vector<int>>& graph) {
 			int n = graph.size();
 			vector<int>color(n, -1);
            
 				queue<int>q;
 				
 			for (int i = 0; i < n; i++) {
 				if (color[i] != -1) continue;
                int curr = 0;
                //for disconnected graph
                q.push(i);
                //initialise first ele of every component with 0 color
 				color[i] = curr;

 				while (!q.empty()) {
 					int t = q.front();
 					q.pop();
            
 					for (auto &x : graph[t]) {
 						if (color[x] == -1) {
 							color[x] = 1-color[t];
 							q.push(x);
 						} else if (color[x] == color[t]) {
 							return false;
 						}
 					}
 				}
 			}

 			return true;
 		}
 	};
