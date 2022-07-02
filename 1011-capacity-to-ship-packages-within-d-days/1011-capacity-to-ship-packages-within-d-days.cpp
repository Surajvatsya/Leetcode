class Solution {
public:
    
    
    bool isPossible(int l, int r, int n, int d, int mid, vector<int>& w){
        int sum = 0;
        int day = 1;
        for(int i=0; i<n; i++){
            sum+=w[i];
            if(sum>mid){
                day++;
                sum = w[i];
            }
            if(day>d)
                return false;
            
        }
        return true;
    }
    
    
    
    
    
    int shipWithinDays(vector<int>& w, int d) {
        int n = w.size();
        int sum = 0;
        int mx = 0;
        for(int i=0; i<n; i++){
            sum+=w[i];
            mx = max(mx,w[i]);
        }
        int l = mx;
        int r=sum;
        int ans = -1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(isPossible(l,r,n,d,mid,w)){
                ans = mid;
                r = mid-1;
            }
            else
                l = mid+1;
        }
        return ans;
    }
};