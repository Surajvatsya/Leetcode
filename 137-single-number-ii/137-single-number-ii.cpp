class Solution {
public:
    
    
    
    int singleNumber(vector<int>& nums) {
        vector<int>ans(32,0);
       
        for(int i=0; i<nums.size(); i++){
            long long a = nums[i];
             int j=0;
            
            //handle -ve
            if(nums[i]<0)
            {
                a = a&INT_MAX;
                long long b = (long long )INT_MAX+1;
                //2147483648
                a=a | b;
            }
            
            while(a){
                ans[j]+=a&1;
                a = a>>1;
                j++;
            }
        }
        
        // reverse(ans.begin(), ans.end());
        
         for(int i=0; i<ans.size(); i++){
            
             ans[i]=ans[i] % 3;
             
             
         }
        
        long long base = 1;
        int dec_val=0;
        for(int i=0; i<32; i++){
            
            dec_val+=ans[i]*base;
            base*=2;
        }
        
        
        return  dec_val;
    }
};