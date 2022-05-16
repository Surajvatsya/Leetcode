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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*slow=head;
        ListNode*fast=head;
        
        
        //since minm n node hoga hi, so fast=fast->next; me fast null na ho jay iska dar n h
        while(n--){
            fast=fast->next;
        }
        
        //now check here agar n node hi hua to fast to null ho gya hoga iska matlab head wala ko hi delete krna h
      //  1 2 3 4 n=4
        
        if(!fast)
            return head->next;
        
        while(fast->next){
            fast=fast->next;
            slow=slow->next;
        }
        
        slow->next= slow->next->next;
        return head;
        
    }
};