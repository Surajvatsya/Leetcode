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
    
    TreeNode* solve(vector<int>& preorder, int psi, int pei, vector<int>& inorder, int isi, int iei ){
        
        
        if(psi > pei)
            return nullptr;
        
        int idx = isi;
        
        while(preorder[psi]!=inorder[idx])
            idx++;
        
        TreeNode* node = new TreeNode(preorder[psi]); //3
        
        int lstc = idx - isi ; //1
        
        //3
        
        node-> left = solve(preorder, psi+1, psi+lstc, inorder, isi, idx-1);
        node->right = solve(preorder, psi+lstc+1, pei, inorder, idx+1, iei);
        
        
        return node;
        
        
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        
        int n = preorder.size();
        
        return solve(preorder, 0, n-1, inorder, 0, n-1);
        
        
    }
};