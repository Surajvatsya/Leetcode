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
    
    void inorder(TreeNode* root, vector<int>&arr){
        if(root == NULL)
            return;
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }
    
     vector<int> sort2Araay(vector<int>&a, vector<int>&b){
         vector<int>ans;
         int n = a.size();
         int m = b.size();
         int i = 0, j=0;
         while(i<n and j<m){
             if(a[i]<b[j]){
                 ans.push_back(a[i]);
                 i++;
             }
             else{
                 ans.push_back(b[j]);
                 j++;
             }
         }
         
         while(i<n){
             ans.push_back(a[i]);
                 i++; 
         }
         while(j<m)
         {
              ans.push_back(b[j]);
                 j++;
         }
         return ans;
     }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>a;
        vector<int>b;
       
        if(root1==NULL and root2==NULL)
            return a;
        if(!root1)
        {
             inorder(root2,b);
            return b;
        }
        if(!root2){
            inorder(root1,a);
            return a;
        }
        
        inorder(root1,a);
        inorder(root2,b);
        return sort2Araay(a,b);
        
    }
};