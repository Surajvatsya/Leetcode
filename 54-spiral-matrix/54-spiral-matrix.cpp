class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
       
        int n = matrix.size();
        int m = matrix[0].size();
        int left =0;
        int right=m-1;
        int up = 0;
        int down = n-1;
        
        char dir = 'e';
        
//make sure ki left and right dono  equal pe v chle up<=down and right>=left
        
        while(up<=down and right>=left){
            if(dir=='e'){
                for(int i=left; i<=right; i++){
                    ans.push_back(matrix[up][i]);
                }
                up++;
                dir = 's';
            }
           else if(dir=='s'){
                for(int i=up; i<=down; i++){
                    ans.push_back(matrix[i][right]);
                }
                right--;
                dir = 'w';
            }
           else if(dir=='w'){
                for(int i=right; i>=left; i--){
                    ans.push_back(matrix[down][i]);
                }
                down--;
                dir = 'N';
            }
           else if(dir=='N'){
                for(int i=down; i>=up; i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
                dir = 'e';
            }
        }
        return ans;
    }
};