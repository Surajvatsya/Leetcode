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
}
void inorders(TreeNode* root){
if(!root)
return;
inorders(root->left);
if(v[0]!=root->val){
root->val = v[0];
}
v.erase(v.begin());
inorders(root->right);
}
void recoverTree(TreeNode* root) {
inorder(root);
sort(v.begin(), v.end());
inorders(root);
}
};
```