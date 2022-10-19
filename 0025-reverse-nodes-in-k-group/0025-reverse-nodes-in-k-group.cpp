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
    ListNode* reverseKGroup(ListNode* head, int k) {
        //base case
        //if k element ios not there
        ListNode* temp = head;
        for(int i=0; i<k; i++){
            if(!temp)
                return head;
            
            temp = temp->next;
        }
        
        
        //reverse k element
        ListNode* curr = head;
        ListNode*  nxt;
        ListNode* prev = NULL;
      for(int i=0; i<k; i++)  {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr= nxt;
        }
        
        if(curr)
            head->next = reverseKGroup( curr,  k);
        
        return prev;
    }
};