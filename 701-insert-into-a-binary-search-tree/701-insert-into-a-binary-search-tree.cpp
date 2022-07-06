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
    TreeNode* insertIntoBST(TreeNode* root, int data) {
        if(!root)
        {
            TreeNode* nn = new TreeNode(data);
            return nn;
        }
        if(root->val<data )
          root->right =  insertIntoBST(root->right,data) ;
         if(root->val>data )
         root->left =  insertIntoBST(root->left,data) ;
        return root;
        
    }
};