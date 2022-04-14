class Solution {
public:
    
    
    bool issafe(vector<vector<char>>& board, int row, int col, char c){
        for(int i=0; i<9; i++){
            if(board[i][col]==c)
                return false;
            if(board[row][i]==c)
                return false;
            
            int horizon_lvl = row/3;
            int i_index = 3 * horizon_lvl;
            
            int vertical_level = col/3;
            int j_index = 3 * vertical_level;
            
            if(board[i_index+i/3][j_index+i%3]==c)
                return false;
            
        }
        return true;
    }
    
    
    bool solve(vector<vector<char>>& board){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]=='.'){
                    for(char c='1'; c<='9'; c++){
                        if(issafe(board, i,j,c)){
                            board[i][j]=c;
                            
                        if(solve(board))
                            return true;
                        else
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
               
            }
        }
        return true; 
    }
    
    
    void solveSudoku(vector<vector<char>>& board) {
        
        solve(board);
        
    }
};