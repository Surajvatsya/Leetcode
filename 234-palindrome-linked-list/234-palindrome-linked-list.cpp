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
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL)
            return true;
        
        ListNode*slow = head;
        ListNode*fast = head;
        ListNode* prev = NULL;
        ListNode* nxtptr;
        while(fast and fast->next){
            fast = fast->next->next;
            nxtptr = slow->next;
            slow->next=prev;
            prev=slow;
            slow=nxtptr;
           
            // this is wrong bcs fast next is null right now
            // fast = fast->next->next;
            
        }
        
        slow = fast? slow->next :slow  ;
        
        while(slow){
            if(slow->val!=prev->val)
                return false;
            slow=slow->next;
            prev=prev->next;
        }
        return true;
    }
};