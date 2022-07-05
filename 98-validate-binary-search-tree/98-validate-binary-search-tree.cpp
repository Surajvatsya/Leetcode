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

// [10,5,null,null,12]
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        return isBST(root,NULL,NULL);
    }
    
    bool isBST(TreeNode* root,TreeNode* min, TreeNode* max){
        
        if(!root)
            return true;
        
        if((max!=NULL and root->val>=max->val) or (min!=NULL and root->val<=min->val))
        return false;
        
        //check wheather left subtree is valid bst or not
        bool leftsubtree = isBST(root->left, min, root);
        
        //check wheather right subtree is valid bst or not
         bool rightsubtree = isBST(root->right, root, max);
        
        // if both are valid return true
        return  leftsubtree and rightsubtree;
    }
    
    
};