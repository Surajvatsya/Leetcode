class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int i=0;
        int j=0;
        int n = nums.size();
        vector<int>v(32,0);
        int mx = 1;
        
        while(j<n){
            
            //find ele at j
            int ele = nums[j];
            int k=0;
            
            while(ele){
                int a = ele & 1;
                v[k++] += a;
                ele = ele>>1;
            }
            
            //check ki 32 bit me se khi v freq 1 se jyada hua to i++
            //else j++;
            
            int f=0;
            for(int m=0; m<32; m++){
                
                if(v[m]>1){
                    //erase bit of nums[i]
                    int erase_ele = nums[i];
                    int p=0;
                        while(erase_ele){
                        int a = erase_ele & 1;
                        v[p++] -= a;
                        erase_ele = erase_ele>>1;
                       }
                    i++;
                    break;
                    f=1;
                }
            
                
            }
            
            mx = max(mx,j-i+1);
            
            j++;
            
            
            
        }
        return mx;
    }
};