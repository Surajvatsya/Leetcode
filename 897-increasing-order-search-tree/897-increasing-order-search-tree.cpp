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
    TreeNode* newnode= new TreeNode(0);
    TreeNode* head = newnode;
    void inorder(TreeNode*root){
        if(!root)return;
        inorder(root->left);
        //do operation whatever u want to
        
        newnode->right=new TreeNode(root->val);
        newnode=newnode->right;
        inorder(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        if(!root) return root;
        inorder(root);
        return head->right;
    }
};

//Time Complexity: O(N), where NN is the number of nodes in the given tree. b/c u visited every node

//sc = O(h)  where HH is the height of the given tree, 
// worst case me sc = o(N) skew tree me, otherwise O(logn)