class Solution {
public:
    
   int binarySearch(vector<int>& nums, int target, int s, int e){
       while(s<=e){
           int mid =(s+e)/2;
           if(nums[mid]==target)
               return mid;
           else if(nums[mid]<target){
               s=mid+1;
           }
           else
               e=mid-1;
       }
       return -1;
   }
    
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        return binarySearch(nums,target,0,n-1);
    }
};