/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *   int val;
 *   TreeNode * left;
 *   TreeNode * right;
 *   TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:

        void solve(TreeNode *root, string s, int &sum)
        {
           	//base case
            if (root==NULL)
                return;
            
                s += to_string(root->val);
              // cout<<s;

            if ( root->left == NULL and root->right == NULL)
            {
                
                
                sum += stoi(s);
              
                return;
            }

            
                solve(root->left, s, sum);

                solve(root->right, s, sum);
            
        }

    int sumNumbers(TreeNode *root)
    {
        string s = "";
        int sum = 0;
        solve(root, s, sum);
        return sum;
    }
};