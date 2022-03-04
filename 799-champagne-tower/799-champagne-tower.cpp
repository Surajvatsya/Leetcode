class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double v[100][100] = {0};
        v[0][0] = poured;
        for(int i=0; i<query_row; i++){
            for(int j = 0; j<=i; j++){
                double flow = (v[i][j] - 1)/2.0;
                
                if(flow>0){
                v[i+1][j]+=flow;
                v[i+1][j+1]+=flow; 
                }
            }
        }
        double ans = v[query_row][query_glass];
        
        //suppose poured = 100 and r=1,c=1; flow = 99/2.0 = 49.5 ans hoga
        if(ans<1)
            return ans;
        return 1;
    }
};