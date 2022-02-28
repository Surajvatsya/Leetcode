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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        if(!root->left and !root->right)
            return 1;
        
        
        queue<pair<TreeNode*, int>>q;
        
        q.push({root,0});
        
        int ans = -1;
        
        while(!q.empty()){
            int start = q.front().second;
            int end = q.back().second ;
            ans = max(ans, end-start+1);
            int n = q.size();
            for(int i=0; i<n; i++){
                 pair<TreeNode*, int>temp = q.front();
                  int idx = temp.second;
                 q.pop();
              
                 if(temp.first->left!=NULL)
                     q.push({temp.first->left, (long long) 2*idx+1});
                if(temp.first->right!=NULL)
                      q.push({temp.first->right, (long long) 2*idx+2});
            }
            
        }
        return ans;
        
    }
};