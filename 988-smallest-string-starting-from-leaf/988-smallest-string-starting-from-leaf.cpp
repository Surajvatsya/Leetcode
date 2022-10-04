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
        void solve(vector<vector < int>> &v, stack< int > st, TreeNode *root)
        {
            if (!root)
                return;

            st.push(root->val);
            
            if (root->left == nullptr and root->right == nullptr)
            {
                vector<int> t;
                while (!st.empty())
                {
                    t.push_back(st.top());
                    st.pop();
                }
                v.push_back(t);
                return;
            }
            
             solve(v, st, root->left);
             solve(v, st, root->right);
        }

    string smallestFromLeaf(TreeNode *root)
    {
        stack<int> st;
        vector<vector < int>> v;
        solve(v, st, root);
        sort(v.begin(), v.end());
        string s = "";
        for(auto &x: v[0])
            s+='a'+x;
        return s;
    }
};