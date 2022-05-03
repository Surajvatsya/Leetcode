class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int n = nums.size();
        if(n==0)
            return 0;
        
        int mx=0;
        unordered_map<int,int> mp;
        
        //store in map to access in O(1)
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }
        
        
        
        for(int i=0; i<n; i++){
            //count andar hoga , every time new count
            int count = 0;
            
            //now ye dekhna h ki jis element ka prev yani parent nhi hoga vhi se consecutive element start hua hoga
           
//                 suppose Input: nums = [100,4,200,1,3,2]
//                 100 no parent(99 nhi h)
//                 so 100 can be a starting element of longest consecutive elements 
//                 so start looking for how many element is  there in consecutive line
                    
//                     similarly for 4, 3 is parent leave it
//                     200 hasnt parent so same opn as we done on 100
//                     1 hasn't any parent so 100 can be a starting element of longest                              consecutive elements 
//                 so start looking for how many element is  there in consecutive line
                        
            
            
            
            
            
            if(mp.find(nums[i]-1)==mp.end())
            {
                int k=0;
                // start looking for how many element after nums[i] is  there in consecutive                   line
                while(1){
                    
                    if(mp.find(nums[i]+k)!=mp.end())
                    {
                        count++;
                        k++;
                    }
                    else
                    break;
                }
                mx = max(mx, count);
            }
               
        }
        return mx; 
    }
};