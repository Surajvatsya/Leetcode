class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
       
        int n = nums.size();
        if(n<=2)
            return true;
        int flag = 1;
        int i;
        int mx = INT_MIN;
        for( i=0; i<n-1; i++){
            
            if(nums[i]>nums[i+1] and mx==INT_MIN)
            {
                 flag = 0;
                nums[i] = nums[i+1];
            }
           
          else  if(nums[i]>nums[i+1] and flag == 0){
                break;
            }
              
            else if(nums[i]>nums[i+1] and mx<=nums[i]){
                 flag = 0;
                if(nums[i+1]>=mx)
                nums[i] = nums[i+1];
                else if(nums[i+1]<mx)
                 nums[i+1] = nums[i];   
                
                i++;
            }
            
                mx= max(mx,nums[i]);
        }
        
         
        for(int k=0; k<n-1; k++){
            if(nums[k]>nums[k+1])
            {
                
                 return false;
            }
        }
        return true;
        
    }
};