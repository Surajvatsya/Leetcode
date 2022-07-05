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
class BSTIterator {
private:
    void inorder(vector<int>&v, TreeNode* root){
        if(!root)
            return;
        inorder(v,root->left);
        v.push_back(root->val);
         inorder(v,root->right);
        
    }
public:
    vector<int>v;
    
    //[3,7,9,15,20]
    
    BSTIterator(TreeNode* root) {
        inorder(v,root);
    }
    int ind = -1;
    int next() {
        return v[++ind];
    }
    
    bool hasNext() {
        return ind+1<v.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */