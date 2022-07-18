/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// brute -> map me dalte jao and check for same 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL)
            return head;
        ListNode * slow = head;
        ListNode * fast = head;
        
        //rem edge case
        //case 1 :single node 
        // if(head->next==NULL)
        //     return head;
        
        ListNode * temp = head;
        int flag = 0;
        //case 2 : if atleast 2 node is there
        while(fast and fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                flag = 1;
                break;
            }
        }
        if(flag){
            while(temp!=slow){
                temp = temp->next;
                slow=slow->next;
            }
            return slow;
        }
        return nullptr;
        
        
        
    }
};