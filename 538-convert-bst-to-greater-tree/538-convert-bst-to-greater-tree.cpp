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
    int s= 0;
    void preorder(TreeNode* root,  vector<int>&v){
        if(!root)
            return;
        s+=root->val;
        v.push_back(root->val);
        preorder(root->left, v);
        preorder(root->right, v);
    }
    
    
    void traverse(TreeNode* root,  unordered_map<int, int> &mp){
        if(!root)
            return;
        int temp = root->val;
        int replace = mp[temp];
        root->val = replace;
       
        traverse(root->left, mp);
        traverse(root->right, mp);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        vector<int>v;
        unordered_map<int, int> mp;
        
        if(!root)
            return root;
        preorder(root, v);
        sort(v.begin(), v.end());
        int sum = 0;
        int n = v.size();
         vector<int>t(n);
        t[0] = s;
        for(int i=1; i<v.size(); i++){
            sum+=v[i-1];
            t[i]=s-sum;
            
        }
        
        for(int i=0; i<n; i++){
            mp[v[i]]=t[i];
        }
        
        traverse(root, mp);
        return root;
    }
};