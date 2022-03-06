class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        map<int,int>mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]=i;
        }
        long long start = 1;
        long long sum = 0;
        for(auto &x : mp ){
            long long end = x.first;
            if(end - start <= k){
                sum += (end-1)*(end-1 +1)/2  - (start-1)*(start -1 +1)/2;
               
                k -= end - start;
                 start = end + 1;
                if(k<=0)
                    break;
            }
            else{
               break;
            }
        }
        
        if(k>0){
            // start==7
            long long end = start+k;
             sum += (end-1) * (end-1 +1)/2  - (start-1) * (start -1 +1)/2;
        }
        return sum;
        
        
        
    }
};