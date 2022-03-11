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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0 or !head or !head->next)
            return head;
        
        int count = 0;
        ListNode* temp = head;
        while(temp){
            count++;
            temp=temp->next;
        }
            k=k%count;
         if(k==0)
            return head;
        
        int restlength = count-k;
        ListNode* p = head;
        int i=0;
            while(i<restlength-1){
                p = p->next;
                i++;
            }
        ListNode*  newHead = p->next;
        ListNode*  finalHead = newHead;
        p->next = NULL;
        while(newHead->next!=NULL)
            newHead=newHead->next;
        newHead->next = head;
        return finalHead;
    }
};