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
class Solution {
private :
 void    solve(int &sum ,TreeNode* root, int low, int high ){
        if(!root)
            return;
        if(root->val<=high and root->val>=low)
            sum+=root->val;
        
         solve(sum, root->left, low,high);
         solve(sum, root->right, low,high);
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
     if(!root)
         return 0;
        int sum = 0;
        solve(sum, root, low,high);
        return sum;
        
    }
};