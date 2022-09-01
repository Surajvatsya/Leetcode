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
public:
    int count=0;
    void solve(TreeNode* root, int mx){
        if(!root)
            return;
        mx = max(mx,root->val);
        if(root->val>=mx)
            count++;
         solve(root->left, mx);
         solve(root->right, mx);
    }
    int goodNodes(TreeNode* root) {
        int mx = INT_MIN;
        solve(root, mx);
        return count;
    }
};