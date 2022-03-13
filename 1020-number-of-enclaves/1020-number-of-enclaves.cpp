// class Solution {
// public:
    
//     void change(int i, int j, vector<vector<int>>& grid){
       
//         if(i<0 or i==grid.size() or j <0; j==grid[0].size())
//            return;
        
       
//              if(grid[i][j]==1){
                 
//                     grid[i][j]=-1;
//                     change(i+1,j,grid);
//                      change(i-1,j,grid);
//                      change(i,j-1,grid);
//                      change(i,j+1,grid);
                 
//             }
        
            
//     }
    
//     int numEnclaves(vector<vector<int>>& grid) {
        
//         if(grid.size()==0)
//             return 0;
        
//         for(int i=0; i<grid.size(); i++){
//             for(int j=0; j<grid[i].size(); j++){
//                 if(i==0 or i==grid.size()-1 or j == 0 or j==grid[i].size()-1){
//                     if(grid[i][j]==1)
//                       change(i,j,grid);
//                 }
//             }
//         }
//         int count =0;
        
//         for(int i=0; i<grid.size(); i++){
//             for(int j=0; j<grid[i].size(); j++){
//                 if(grid[i][j]==1){
//                   //count cell
//                     count++;
//                 }
//                 cout<<count;
//             }
//         }
        
//         return count;
        
//     }
// };
class Solution {
 	int rows, cols;
 	void dfs(vector<vector<int>>& A, int i, int j) {
 		if (i < 0 || j < 0 || i >= rows || j >= cols)
 			return;

 		if (A[i][j] != 1) 
 			return;

 		A[i][j] = 0;
 		dfs(A, i+1, j);
 		dfs(A, i-1, j);
 		dfs(A, i, j+1);
 		dfs(A, i, j-1);
 	}
 public:
 	int numEnclaves(vector<vector<int>>& A) {

 		if (A.empty()) return 0;

 		rows = A.size();
 		cols = A[0].size();
 		for (int i = 0; i < rows; i++) {
 			for (int j = 0; j < cols; j++) {
 				if (i == 0 || j == 0 || i == rows-1 || j == cols-1)
 					dfs(A, i, j);
 			}
 		}

 		int ans = 0;
 		for (int i = 0; i < rows; i++) {
 			for (int j = 0; j < cols; j++) {
 				if (A[i][j] == 1)
 					ans++;
 			}
 		}

 		return ans;
 	}
 };