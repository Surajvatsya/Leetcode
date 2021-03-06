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
            
            
            if(head->val==data)
            {
                 head=head->next;
                //impo line ...nhi to niche ka chal jayga
                return head;
            }
            
            // //single node
            // if(head->next==NULL)
            //     if(head->val==data)
            //         head=head->next;
                
             ListNode* temp = head;
            while(temp and temp->next){
                //yha temp ka value compare nai hua h, temp ka next ka, suppose temp ka value hi data k brabar hua to
                if(temp->next->val==data){
                    ListNode* p = temp->next;
                    temp->next=p->next;
                    delete p;
                    return head;
                }
                temp=temp->next;
            }
            return head;
            
            
//         if(head->val == data)
//         {
//               head=head->next;
//               return head;
//         }
//         ListNode* temp = head;
//         ListNode*p;

//         //single node
//         if(temp->next == NULL)
//            {
//              temp=temp->next;
//              return head;
// 	    }
            
//         while(temp and temp->next and temp->next->val!=data){
//             temp=temp->next;
//         }
//         p = temp->next;
//         temp->next = p->next;
//         p->next=NULL;
//         delete p;
//         return head;
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