class Solution {
public:
    
    void dfs (vector<vector<char>>& A, int i,int j,int rows,int cols){
        if(i<0 or j<0 or j==cols or i == rows)
            return;
        if(A[i][j]=='1'){
            A[i][j]='*';
            dfs(A,i-1,j,rows,cols);
            dfs(A,i+1,j,rows,cols);
            dfs(A,i,j+1,rows,cols);
            dfs(A,i,j-1,rows,cols);
        }
    }
    int numIslands(vector<vector<char>>& A) {
        
        
 		if (A.empty()) return 0;

 		int rows = A.size();
 		int cols = A[0].size();
        int count = 0;
 		for (int i = 0; i < rows; i++) {
 			for (int j = 0; j < cols; j++) {
                if(A[i][j]=='1')
                {
                     dfs(A,i,j,rows,cols);
                         count++;
                }
            }
        }
        return count;
        
    }
};