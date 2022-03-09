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
    
        
        ListNode* del_node(ListNode*head, int data){
        if(head == NULL)
            return head;
            
        if(head->val == data)
        {
              head=head->next;
              return head;
        }
        ListNode* temp = head;
        ListNode*p;

        //single node
        if(temp->next == NULL)
           {
             temp=temp->next;
             return head;
	    }
            
        while(temp and temp->next and temp->next->val!=data){
            temp=temp->next;
        }
        p = temp->next;
        temp->next = p->next;
        p->next=NULL;
        delete p;
        return head;
    }
    ListNode* deleteDuplicates(ListNode* head) {
         
        if(head == NULL)
            return head;
        unordered_map<int,int>mp;
        ListNode* temp = head;
        while(temp){
            mp[temp->val]++;
            temp=temp->next;
        }
        for(auto x: mp){
            while(x.second>1){
              for(int i = 0;i<x.second;i++){
                  head = del_node(head, x.first); 
              } 
                x.second=0; 
            }
            }
        return head;
    }
};