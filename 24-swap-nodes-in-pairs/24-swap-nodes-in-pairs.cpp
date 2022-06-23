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
    ListNode* swapPairs(ListNode* head) {
        if(!head or !head->next) return head;
        ListNode*ans = head->next;
        ListNode*i = head;
       
        int flag = 0;
        
        while(1){
            ListNode*j = i->next;
           ListNode*temp = j->next;
            j->next = i;
           //even or odd case
            if(!temp or !temp->next){
                i->next=temp;
                break;
            }
           
            i->next=temp->next;
             i=temp;
           
            
        }
        return ans;
    }
};