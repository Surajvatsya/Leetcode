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
    
    void inorder(TreeNode* root,  vector<int> &v){
        if(!root)
            return ;
       
        //inorder left
        inorder(root->left, v);
        //business
        v.push_back(root->val);
        //right
        inorder(root->right, v);
    }
    void change(TreeNode* root,  vector<int> &v){
        if(!root)
            return ;
        // cout<<1;
        //inorder left
        change(root->left, v);
        //business
           root->val = v[0];
           v.erase(v.begin() + 0);
        //right
        change(root->right, v);
         
    }
    
    
    TreeNode* convertBST(TreeNode* root) {
        if(!root)
            return root;
        
        //find inorder
        vector<int> v;
        inorder(root,v);
        
        int n = v.size();
       
        long s=0;
        for(int i=n-1; i>=0; i--){
            s+=v[i];
            v[i]=s;
        }
         // cout<<s;
        
        change(root,v);
        return root;
    }
};