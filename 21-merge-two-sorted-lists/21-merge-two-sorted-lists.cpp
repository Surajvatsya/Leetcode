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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
     ListNode* temp1=l1;
     ListNode* temp2=l2;
     ListNode*dn = new ListNode(-1);
      ListNode* temp3 = dn;  
        while(temp1 and temp2)
        {
            if(temp1->val<temp2->val)
            {
                temp3->next=temp1;
                 temp3 = temp1;
                temp1=temp1->next;
            }
            else
            {
                temp3->next = temp2;
                temp3=temp2;
                temp2=temp2->next;
            }
        }
        if(temp1)
        {
            temp3->next=temp1;
        }
        if(temp2)
        {
            temp3->next=temp2;
        }
        return dn->next;
    }
};