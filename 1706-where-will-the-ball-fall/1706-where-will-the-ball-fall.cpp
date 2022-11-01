// class Solution
// {
//     public:
//         vector<int> findBall(vector<vector < int>> &grid)
//         {
//             int row = grid.size();
//             int col = grid[0].size();
//             vector<int> v(col, -1);
//             int i = 0;
//             int k = 0;
//             int j = 0;
//             while (k < col)
//             {
//                 if (i == row)
//                 {
//                     v[k] = j;
//                     i = 0;
//                     k++;
//                     j = k;
//                     // continue;
//                 }

//             else if ((j == 0 and grid[i][j] == -1) or(j == col - 1 and grid[i][j] == 1))
//                 {
//                     i = 0;
//                     k++;
//                     j = k;
//                     // continue;
//                 }

//              else if (j > 0 and j < col - 1 and ((grid[i][j] == 1 and grid[i][j + 1] == -1) or(grid[i][j - 1] == 1 and grid[i][j] == -1)) )
//                 {
//                     i = 0;
//                     k++;
//                     j = k;
//                     // continue;
//                 }

//               else if (grid[i][j] == 1)
//                 {
//                     i++;
//                     j++;
//                 }
//                 else if (grid[i][j] == -1)
//                 {
//                     i++;
//                     j--;
//                 }
//             }
//             return v;
//         }
// };

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> result(grid[0].size(), 0);

        for (int col = 0; col < grid[0].size(); col++) {
            int currentCol = col;
            for (int row = 0; row < grid.size(); row++) {
                int nextColumn = currentCol + grid[row][currentCol];
                if (nextColumn < 0 || nextColumn > grid[0].size() - 1 ||
                    grid[row][currentCol] != grid[row][nextColumn]) {
                    result[col] = -1;
                    break;
                }
                result[col] = nextColumn;
                currentCol = nextColumn;
            }
        }
        return result;
    }
};
