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
   
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA or !headB)
            return NULL;
         set<ListNode*>mp;
        ListNode *temp1 = headA;
        while(temp1){
            mp.insert(temp1);
            temp1=temp1->next;
        }
        ListNode *temp2 = headB;
      while(temp2){
            if(mp.find(temp2)!=mp.end())
                return temp2;
          temp2=temp2->next;
        }  
        return NULL;
    }
};