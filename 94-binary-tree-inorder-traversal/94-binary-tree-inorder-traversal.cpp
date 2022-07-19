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
    vector<int> inorderTraversal(TreeNode* root) {
         vector<int> v;
        stack<TreeNode*>st;
        TreeNode* curr = root;
        
        while(!st.empty() or curr!=NULL){
            
            while(curr){
                st.push(curr);
                curr=curr->left;
           }
            curr = st.top();
                st.pop();
                // cout<<x->val;
                v.push_back(curr->val);  
            
            curr=curr->right;
        }
        return v;
    }
};