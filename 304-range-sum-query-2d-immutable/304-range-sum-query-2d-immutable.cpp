class NumMatrix {
public:
    vector<vector<int>>m;
    NumMatrix(vector<vector<int>>& matrix) {
       for(int i=0; i<matrix.size(); i++){
           int s=0;
           for(int j=0; j<matrix[0].size(); j++){
               matrix[i][j]+=s;
               s=matrix[i][j];
           }
       }
        m=matrix;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        long s=0;
        long mm=0;
        for(int i=row1; i<=row2; i++)
        {
                 s+=m[i][col2];
                 if(col1>0)
                     mm+=m[i][col1-1];
        }
        return s-mm;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */