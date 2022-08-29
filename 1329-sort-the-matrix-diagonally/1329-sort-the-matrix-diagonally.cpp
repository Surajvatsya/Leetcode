typedef pair<int, int> pi;
#define debug(x) cout<<#x<<" = "<<x<<endl;
class Solution {
public:
    vector<vector<int>>ans;
    
    void solve(int i, int j, vector<vector<int>>& mat){
         int n = mat.size();
        int m = mat[0].size();
        
        vector<int>v;
        while(i<n and j<m){
            v.push_back(mat[i][j]);
            i++;
            j++;
        }
        sort(v.begin(), v.end());
        ans.push_back(v);
    }
     void fill(int i, int j, vector<vector<int>>& mat, int k){
          int n = mat.size();
        int m = mat[0].size();
        
        vector<int>v = ans[k] ;
         int ind = 0;
        while(i<n and j<m){
           mat[i][j] = v[ind];
            i++;
            j++;
            ind++;
        }
        
    }
    
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
      
        int n = mat.size();
        int m = mat[0].size();
        
         int i = 0;
         int j = m - 1;
        while(j>=0){
            solve(i,j, mat);
            j--;
        }
        i=1;
        j=0;
        while(i<n){
          solve(i,j, mat);
            i++;
        } 
        int k = 0;
        //again taverse diagonally
         i = 0;
         j = m - 1;
        while(j>=0){
            fill(i,j, mat, k);
            j--;
            k++;
        }
        
        i=1;
        j=0;
        while(i<n){
          fill(i,j, mat, k);
            i++;
            k++;
        } 
        
          return mat;
    }
};