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
    void reorderList(ListNode* head) {
        //edge case 1 node 2 node 
        if(head->next==NULL or head->next->next==NULL)
            return;
        
        //stack
        stack<ListNode* >st;
        ListNode* temp = head;
        int count = 0;
        while(temp){
            st.push(temp);
            temp=temp->next;
            count++;
           
        }
        
       
        
        ListNode* temp1 = head;
        ListNode* temp2 = head->next;
          ListNode* node ;
        for(int i=0; i<count/2; i++){
            node = st.top();
            st.pop();
            
            temp1->next=node;
            node->next=temp2;
            temp1 = temp2;
            temp2=temp2->next;
        }
        if(count%2==0)
        node->next = nullptr;
        else
              node->next->next = nullptr;
        
    }
};