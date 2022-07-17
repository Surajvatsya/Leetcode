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
    bool hasCycle(ListNode *head) {
        if(!head)
            return false;
        
        ListNode * fast =head;
        ListNode * slow = head;
        
        while(  fast!=NULL and  fast->next!=NULL){
            slow = slow->next;
            
            //fast ka next access kr rha h to fast shouldnt be null and fast->next should be null bcs fast->next->next access ho rha h
            fast = fast->next-> next;
            if(slow==fast)
                return true;
        }
        return false;
        
    }
};