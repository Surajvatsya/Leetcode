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
private:
     TreeNode* prev=NULL;
    void inorder( TreeNode* root, TreeNode* &first,  TreeNode* &second,  TreeNode* &mid){
        if(!root)
            return;
        
        inorder(root->left, first,second,mid);
        
        if(prev!=NULL and prev->val > root->val){  
            
            if(first==NULL){
                 first = prev;
                 mid = root;
            }
            else{
                second = root;
            }  
        }
        
            prev = root;
        
            
         inorder(root->right, first,second,mid);
    }
    
public:
    void recoverTree(TreeNode* root) {
        TreeNode* first =NULL;
        TreeNode* second = NULL;
        TreeNode* mid = NULL;
        inorder(root, first,second,mid);
        if(second==NULL)
            swap(first->val, mid->val);
        else
             swap(first->val, second->val);
        
    }
};