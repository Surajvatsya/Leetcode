class Solution {
public:
    
    void change(int i,int j,vector<vector<char>>& board){
        // i==3
        // j==1
        board[i][j]='*';
        int dx[]={0,0,-1,1};
        int dy[]={1,-1,0,0};
        
       for(int k = 0;k<4;k++){
           int cx = i+dx[k];
           int cy = j+dy[k];
           
           // cx = 3+ 1;
           // cy = 1 + (0);
           
           
           if(cx>=0 and cx<board.size() and cy>=0 and cy<board[0].size()  and board[cx][cy]=='O')
               change(cx,cy,board);
       }
        
    }
    
    void solve(vector<vector<char>>& board){
         for(int i = 0; i<board.size(); i++){
            for(int j = 0; j<board[i].size();j++){
                if(i==0 or i ==board.size()-1 or j == 0 or j == board[i].size()-1)
                {
                  if(board[i][j]=='O')
                        change(i,j,board);  
                }
            }
         }
        for(int i = 1; i<board.size()-1; i++){
            for(int j = 1; j<board[i].size()-1;j++){            
                    if(board[i][j]=='O')
                        board[i][j]='X';
            }
        }
        for(int i = 0; i<board.size(); i++){
            for(int j = 0; j<board[i].size();j++){
               
                    if(board[i][j]=='*')
                        board[i][j]='O';
               
            }
        }
        
    }
};