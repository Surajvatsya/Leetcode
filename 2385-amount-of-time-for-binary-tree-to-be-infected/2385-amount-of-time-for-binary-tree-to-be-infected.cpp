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
    unordered_map<int, vector<int>> mp;
     unordered_map<int, bool> vis;
    
    void creategraph(TreeNode* child_node, int parent=-1){
        
        if(parent!=-1){
            int child = child_node->val;
            mp[parent].push_back(child);
            mp[child].push_back(parent);
        }
        
        if(child_node->left) creategraph(child_node->left, child_node->val);
        if(child_node->right) creategraph(child_node->right, child_node->val);
        
    }
     
   
    int mx = 0;
    void dfs(int start, int t){
        
        t++;
        mx = max(mx, t);
        //  cout<<endl;
        // cout<<mx<<endl;
        vis[start]=true;
        for(auto &y : mp[start]){
            // for(auto &y : x.second)
                if(!vis[y])
                  dfs(y, t);
        }
            
    }
    
     
    
    
    
    int amountOfTime(TreeNode* root, int start) {
        //create graph
        creategraph(root);
        
    //     for(auto &x : mp){
    //     cout<<x.first<<" ";
    //     for(auto &y : x.second)
    //         cout<<y<< " ";
    //     cout<<endl;
    // }
        
       int t=0;
        dfs(start, t);
        
        return mx-1;
        
    }
};