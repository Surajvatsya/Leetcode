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
    ListNode* swapNodes(ListNode* head, int k) {
        if(!head)
            return head;
        
        ListNode* temp1 = head;
        ListNode* temp = head;
        ListNode* temp3 = head;
        int i=0;
        
        while(i<k-1){
            //i<1
            temp1=temp1->next;
            i++;
            
        }
        int count = 0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
            
        }
        
        int li = count - k;
        int j = 0;
         while(j<li){
            //j<3
            temp3=temp3->next;
             j++;
            
        }
        int ele = temp1->val;
        temp1->val = temp3->val;
        temp3->val = ele;
        // delete temp1;
        // delete temp3;
        // delete temp;
        return head;
    }
};