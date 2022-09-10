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
    int res = INT_MIN;
    
    int diameterOfBinaryTre(TreeNode* root){
         if(!root)
            return 0;
      int l =   diameterOfBinaryTre( root ->left);
      int r =   diameterOfBinaryTre( root->right );
        
        int temp = 1+max(l,r);
        int ans = max(temp , 1+l+r);
        res = max(res, ans);
        return temp;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
       diameterOfBinaryTre(root);
        return res-1;
        
    }
};