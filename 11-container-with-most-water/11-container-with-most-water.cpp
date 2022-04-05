class Solution {
public:
    int maxArea(vector<int>& height) {
        
        
        
        int mx = INT_MIN;
        int n = height.size();
        int i = 0;
        int j = n-1;
        
        
        while(i<j){
            int minht = min(height[i], height[j]);
            int width = j-i;
            
            mx = max(mx, minht*width);
            if(height[i]==minht)
                i++;
            else
                j--;
            
        }
        return mx;   
    }
};