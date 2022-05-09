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


// try to think edge cases 

// concept -> prev curr nxt lekr chlo
//jab v delete krna ho and link krna ho middle nodes me try 2 pointer concept
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(!head)
            return head;
        
        ListNode* dn = new ListNode(-1);
        dn->next = head;
        
        ListNode*curr = head;
        ListNode*prev = dn;
        ListNode*nxt;
        
        while(curr and curr->next){
            nxt = curr->next;
            
            //always think khi nullptr ko access na krlo tm.
            //suppose x->next likh rhe ho make sure that x isn't null.
            if(curr->val == nxt->val){
                 ListNode* temp = nxt;
                while(temp and temp->val==nxt->val){
                    temp=temp->next;
                }
                curr=temp;
                prev->next = curr;
                
            }
            else if(curr->val != nxt->val){
                prev = curr;
                 curr=nxt;
            }
            
            
        }
        
        return dn->next;
    }
};