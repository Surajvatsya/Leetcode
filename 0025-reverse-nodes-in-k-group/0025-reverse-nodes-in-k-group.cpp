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
        //k=2
        //check if atleast k element is present or not
        ListNode* temp = head;
        for(int i=0; i<k; i++){
            
            if(temp==NULL)
                return head;
            
            temp=temp->next;
        }
        
        
        //we know that we have atleast k nodes present in our ll, so reverse k node
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nxt ;
        
        for(int i=0; i<k; i++){
            nxt = curr->next; // nxt = 2
            curr->next = prev;// 1->null
            prev = curr;//prev = 1
            curr = nxt;//curr = 2
        }
        
        if(curr!=NULL)
        head->next =  reverseKGroup( curr,  k);
        
        return prev;
        
        
        
        
    }
};