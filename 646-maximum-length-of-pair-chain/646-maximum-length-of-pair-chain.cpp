class Solution {
public:
    int findLongestChain(vector<vector<int>>& p) {
        
        sort(p.begin(),p.end());
        int len = 1;
        int n = p.size();
        
		// for(int i=0; i<p.size(); i++) 
		// for(int j=0; j<p[i].size(); j++) 
		// cout<<p[i][j]<<" ";
		// cout<<endl;
        
        int v = p[0][1];
        for(int i=1; i<n; i++){
            if(p[i][0]>v)
            {
                len++;
                v = p[i][1];
            }
            else{
                if(p[i][1]<v)
                  v = p[i][1];
            }
            
        }
        return len;
        
    }
};