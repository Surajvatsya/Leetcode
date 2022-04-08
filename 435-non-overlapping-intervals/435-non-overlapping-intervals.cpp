
class Solution {
public:
    
    static bool comp(vector<int>&a, vector<int>&b){
        return a[1]<b[1];
}

    
    int eraseOverlapIntervals(vector<vector<int>>& in) {
        sort(in.begin(),in.end(), comp);
        int count = 0;
        int end = in[0][1];
        for(int i=1; i<in.size(); i++){
            if(in[i][0]<end)
                count++;
            else
                end = in[i][1];
        }
        
        return count;
    }
};