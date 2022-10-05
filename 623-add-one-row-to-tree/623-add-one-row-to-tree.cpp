/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *int val;
 *TreeNode * left;
 *TreeNode * right;
 *TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:

        void dfs(int depth, queue<TreeNode*> &q, int val)
        {
            int n = q.size();
 
            if (depth == 0)
            {
                for (int i = 0; i < n; i++)
                {
                    TreeNode *ele = q.front();
                  
                    q.pop();

                    TreeNode *ln = new TreeNode(val);
                    TreeNode *rn = new TreeNode(val);
                    TreeNode *t1 = ele->left;
                    TreeNode *t2 = ele->right;
                    ele->left = ln;
                    ele->right = rn;
                    ln->left = t1;
                    rn->right = t2;
                    
                }
                return;
            }

            for (int i = 0; i < n; i++)
            {
                TreeNode *ele = q.front();
                q.pop();
                if (ele->left)
                    q.push(ele->left);
                if (ele->right)
                {
                    q.push(ele->right);
                    // cout<<7;
                }
            }

            dfs(depth - 1, q, val);
        }

    TreeNode* addOneRow(TreeNode *root, int val, int depth)
    {

        if (depth == 1)
        {
            TreeNode *nr = new TreeNode(val);
            nr->left = root;
            return nr;
        }

        queue<TreeNode*> q;
        q.push(root);

        dfs(depth - 2, q, val);

        return root;
    }
};