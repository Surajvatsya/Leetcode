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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
     ListNode*temp1=l1;
     ListNode*temp2 = l2;
       ListNode*ans = new ListNode(0);
        
        //you can't simply assign here ListNode*t = ans->next;
        ListNode*t = ans;

        int carry = 0;
        while(temp1 or temp2 or carry){
            int vali= temp1?temp1->val:0;
            int valj = temp2?temp2->val:0;
            int sum = vali+valj+carry;
            int value= sum%10;
            carry = sum/10;
            
            //ek node piche rhna h
            ans->next = new ListNode(value);
            ans = ans->next;
            
           
            //this if condn is important
            //bcs suppose agar temp1 null ho gya h to null->next ka likhega\U0001f602
            if(temp1) temp1=temp1->next;
            if(temp2) temp2= temp2->next;
            
        }
        return t->next;
    }
};