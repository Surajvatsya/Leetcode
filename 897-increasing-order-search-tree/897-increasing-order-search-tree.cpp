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
      void solve(TreeNode* root, TreeNode* &temp){
          if(!root)
              return;
           solve(root->left,temp);
           TreeNode* nn = new TreeNode(root->val);
          temp->right=nn;
          temp=nn;
          solve(root->right,temp); 
           
      }
    
    
    TreeNode* increasingBST(TreeNode* root) {
        if(!root)
            return root;
        
        TreeNode* dn = new TreeNode(-1);
        TreeNode*temp = dn;
        solve(root,temp);
            return dn->right;
        
    }
};