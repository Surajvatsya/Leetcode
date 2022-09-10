class Solution {
public:
    int longestCommonSubstr (vector<int>& s1, vector<int>& s2, int n, int m)
    {
        int t[n+1][m+1];
        for(int i=0; i<n+1; i++){
            for(int j=0; j<m+1; j++){
                if(i==0 or j==0)
                    t[i][j]=0;
            }
        }
        
        
        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(s1[i-1]==s2[j-1])
                t[i][j] = 1 + t[i-1][j-1];
                else
                t[i][j] = 0;
            }
        }
        int mx = 0;
        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                mx = max(mx, t[i][j]);
            }
        }
        return mx;
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        return longestCommonSubstr (nums1, nums2, nums1.size(), nums2.size()) ;
    }
};