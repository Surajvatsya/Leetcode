/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#define debug(x) cout<<#x<<" = "<<x<<endl;
class Solution {
public:
    int count=0;
    unordered_map<long long, int> mp;
    void prefixSum(long long sum,TreeNode* root, int t ){
        if(!root)
            return;
        sum+=root->val;
        // cout<<sum<<endl;
        // debug(sum);
        long long pre_sum = sum-t;
        // debug(pre_sum);
        if(mp.find(pre_sum)!=mp.end()){
             count+=mp[pre_sum];
            
        }
           
        mp[sum]++;
        prefixSum(sum,root->left,t);
        prefixSum(sum,root->right,t);
        mp[sum]--;
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        
        
        mp[0]=1;
        prefixSum(0,root,targetSum);
        return count;
        
    }
};