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
    
    int getLength(ListNode *headA){
        if(!headA)
            return 0;
        int count=0;
        while(headA)
        {
             count++;
            headA=headA->next;
        }
        return count;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      int l1 =  getLength(headA);
        int l2 = getLength(headB);
        while(l1>l2){
            headA=headA->next;
            l1--;
        }
        while(l2>l1){
             headB=headB->next;
            l2--;
        }
        while(headA!=headB){
            headA=headA->next;
            headB=headB->next;
            if(!headA or !headB)
                return NULL;
        }
        return headA;
    }
};