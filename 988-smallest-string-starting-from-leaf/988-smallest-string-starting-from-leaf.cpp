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
    void solve(string &prev, string curr, TreeNode* root){
        if(!root)
            return;
        
        curr=(char)( 'a'+root->val) + curr;
        
        if(!root->left and !root->right)
        {
            if(prev.size()>0 ){
                if(prev>curr)
                    prev=curr;
            }
            else{
                prev=curr;
            }
            
            return;
        }
        
         solve(prev, curr, root->left);
         solve(prev, curr, root->right);
        
    }
    
    
    string smallestFromLeaf(TreeNode* root) {
        
        string prev = "";
        string curr = "";
        solve(prev, curr, root);
        return prev;
    }
};