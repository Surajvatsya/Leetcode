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
    TreeNode*pr = new TreeNode(INT_MIN);
    TreeNode*first=NULL;
    TreeNode*mid = NULL;
    TreeNode*last = NULL;
    
    
    void solve(TreeNode* root){
        TreeNode* curr = root;
        
        while(curr){
            
            // check left pointer 
//             10
 //              \
//                 20
                
            if(curr->left == NULL){
                
                // inorder.push_back(curr->val);
                if(!first and curr->val < pr->val){
                    first = pr;
                    mid = curr;
                }
                else if(!last and curr->val < pr->val)
                    last = curr;
                pr = curr;
                    
                
                //no need to preserve curr
                curr= curr->right;
            }
            else{
                
               //  10
               // /    \
               // 5
               // \
               //   6   20
               // preserve curr -> b/c curr->left ka rightmost ko thread bnana h uske sath
               TreeNode*prev = curr->left;
                while(prev->right!=NULL and prev->right!=curr){
                    prev = prev->right;
                }
                //check phle se to thread nhi h
                if(prev->right==NULL){
                    // 2
                    // \
                    // 3
                    // \
                    //  4
                    //create thread
                    prev->right = curr;
                    //when we make thread we do 
                    curr= curr->left;
                }
                else{
                  //   2
                  //  / \
                  // 4   5
                    prev->right = NULL;
                    // inorder.push_back(curr->val);
                     if(!first and curr->val < pr->val){
                    first = pr;
                    mid = curr;
                }
                 else if(!last and curr->val < pr->val)
                    last = curr;
                     pr = curr;
                    //when we break thread we do 
                    curr=curr->right;
                }
                
                        
            }
                
        }
    }
    
    void recoverTree(TreeNode* root) {
        // vector<int> inorder;
          solve(root);
        
        if(!last)
            swap(first->val , mid->val);
        else
            swap(first->val , last->val);
        
    }
};