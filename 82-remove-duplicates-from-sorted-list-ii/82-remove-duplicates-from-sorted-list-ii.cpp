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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(!head)
            return head;
        
        ListNode* dn = new ListNode(-1);
        dn->next = head;
        
        ListNode*curr = head;
        ListNode*prev = dn;
        ListNode*nxt;
        
        while(curr->next){
            nxt = curr->next;
            if(nxt and curr->val == nxt->val){
                 ListNode* temp = nxt;
                while(temp and temp->val==nxt->val){
                    temp=temp->next;
                }
                curr=temp;
                prev->next = curr;
                
            }
            else if(nxt and curr->val != nxt->val){
                prev = curr;
                 curr=nxt;
            }
            if(!curr)
                break;
            
        }
        
        return dn->next;
    }
};