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
private:
    bool palindrome(vector<int>v){
        
        int i=0; int j = v.size()-1;
        while(i<j){
            if(v[i]!=v[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode* >q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int>v;
            
            for(int i=0; i<n; i++){
                TreeNode*  a = q.front();
                q.pop();
                if(a==NULL)
                    v.push_back(INT_MIN);
                else
                v.push_back(a->val);
                
                    if(a){
                        q.push(a->left);
                        q.push(a->right); 
                    }
                   
            }
            
            if(!palindrome(v))
                return false;
        }
        return true;
    }
};