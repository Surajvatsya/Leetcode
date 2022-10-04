/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class FindElements
{
    public:

        void solve(TreeNode *root)
        {

            if (!root)
                return;

            if (root->left)
            {
                root->left->val = 2 *root->val + 1;
            }

            solve(root->left);

            if (root->right)
            {
                root->right->val = 2 *root->val + 2;
            }

            solve(root->right);
        }

    TreeNode * temp;
    FindElements(TreeNode *root)
    {
        temp = root;
        temp->val = 0;
        solve(temp);
    }
    
    
    bool solve(TreeNode *root, int t){
      
        
       if(!root)
            return false;
        
          if(root->val==t)
            return true;
        
        bool l = solve(root->left, t);
        bool r = solve(root->right, t);
        return l or r;
          
    }

    bool find(int target) {
       return solve(temp, target);
    }
};

/**
 *Your FindElements object will be instantiated and called as such:
 *FindElements* obj = new FindElements(root);
 *bool param_1 = obj->find(target);
 */