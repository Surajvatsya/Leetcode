/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST( ListNode* head, ListNode* tail){
        
        //bc
        if(head==tail)
            return NULL;
        
        //find mid
        ListNode* slow=head;
        ListNode* fast = head;
        while(fast!=tail and fast->next!=tail){
            fast =fast->next->next;
            slow=slow->next;
        }
        
        TreeNode* node = new TreeNode(slow->val);
        node->left = sortedListToBST(  head,  slow);
        node->right = sortedListToBST(  slow->next,  tail);
        return node;
        
        
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head)
            return nullptr;
        return sortedListToBST( head, NULL);
    }
};