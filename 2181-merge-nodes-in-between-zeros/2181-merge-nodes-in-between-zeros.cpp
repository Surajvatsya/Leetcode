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
    ListNode* mergeNodes(ListNode* head) {
        
        if(head->val==0 and head->next->val == 0)
            return head;
        
        //rem ye impo statement h, hme kudh ka ll prepare krna h so dn bnaya
        ListNode* dn = new ListNode(-1);
        ListNode* newHead = dn;
        
        
        ListNode* temp = head;
       while(temp){      
        long s = 0;
      
        while(temp->val!=0){
            s+=temp->val;
            temp=temp->next;
        }
         temp=temp->next;
           if(s!=0)
           {
                ListNode* newNode = new ListNode(s);
                dn->next=newNode;
                dn = dn->next;
           }
        
       }
        return newHead->next;
        
    }
};