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
    int deepestLeavesSum(TreeNode* root) {
        if(!root)
            return 0;
        queue<TreeNode*>q;
        q.push(root);
        
        vector<vector<int>>ans;
        while(!q.empty()){    
            int n= q.size();
             vector<int>v;
            for(int i=0; i<n; i++){
                TreeNode* curr = q.front();
                q.pop();
                v.push_back(curr->val);
                ans.push_back(v);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
        long s=0;
        
        for(auto x : ans[ans.size()-1])
            s+=x;
        return s;
    }
};