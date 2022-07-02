class Solution {
public:
    int smallestDivisor(vector<int>& w, int d) {
        int n = w.size();
      int l = 1;
        int r = 1000001;
        int ans = -1;
        while(l<=r){
            int mid = l+(r-l)/2;
            long long sum = 0;
           
            for(auto &x : w){
                float a = (float)x/mid;
                sum+=ceil(a);
            }
                
           
             // for (auto &a : w)
             //    a%mid == 0 ? sum += (a/mid) : sum += (a/mid)+1;
            
            
            if(sum<=d){
                ans = mid;
                r = mid-1;
            }
            else
                l = mid+1;
        }
        return ans;
    }
};