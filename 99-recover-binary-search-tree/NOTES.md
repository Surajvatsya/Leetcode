**Brute force
T = O(Nlogn) b/c visited every node
s = O(N) + O(h) (vector + height 0f bn tree)
​
```
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode() : val(0), left(nullptr), right(nullptr) {}
*     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
*     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
* };
*/
class Solution {
public:
vector<int> v;
void inorder(TreeNode* root){
if(!root)
return;
inorder(root->left);
v.push_back(root->val);
inorder(root->right);