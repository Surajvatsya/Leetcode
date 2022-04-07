// // class Solution {
// // public:
// //     bool isBipartite(vector<vector<int>>& graph) {
// //         int n = graph.size();
// //         vector<int>color(n, -1);
// //         //it'll work for visited array as well
        
// //         queue<int>q;
// //         q.push(0);
// //         int curr = 0;
// //         color[0]=curr;
// //         for(int i=1; i<n; i++){
            
// //             //cheacked here if I have visited it earlier
// //             if(color[i]!=-1)
// //                 continue;
            
// //             while(!q.empty()){
// //                 int ele = q.front();
// //                 q.pop();
                    
// //                     for(auto &x : graph[ele]){
// //                         curr = 1 - curr;
// //                         if(color[x]==-1)
// //                         {
// //                             color[x]=curr;
// //                              q.push(x);
// //                         }
// //                          else if( color[x]!=curr)
// //                             return false;
// //                     }   
// //                 }     
// //             }
// //         return true;
// //     }
// // };


// class Solution {
//  	public:
//  		bool isBipartite(vector<vector<int>>& graph) {
//  			int n = graph.size();
           
//  			vector<int>color(n, -1);
//                     color[0] = 0;
//  				queue<int>q;
//  				q.push(0);

//  			for (int i = 0; i < n; i++) {
//  				if (color[i] != -1) continue;

 				
//  				while (!q.empty()) {
//  					int t = q.front();
//                     int curr = color[t];
//  					q.pop();
//                          curr = curr xor 1;
//  					for (auto &x : graph[t]) {
                        
//  						if (color[x] == -1) {
//  							color[x] = curr;
//  							q.push(x);
//  						}//color[x]!=-1 
//                         else if (color[x] != curr) {
//  							return false;
//  						}
//  					}
//  				}
//  			}

//  			return true;
//  		}
//  	};

class Solution {
 	public:
 		bool isBipartite(vector<vector<int>>& graph) {
 			int n = graph.size();
 			vector<int>color(n, -1);
            
 				queue<int>q;
 				
 			for (int i = 0; i < n; i++) {
 				if (color[i] != -1) continue;
                        q.push(i);
 				color[i] = 0;

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
