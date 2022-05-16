/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp = node->next;
        // *node = *temp;
        node->next = temp->next;
        node->val = temp->val;
        delete temp;
    }
};


// node -> 5, addrs 1
// temp -> 1, addrs 9
    
// *node = *temp;
// it makes node -> 1, addrs 9