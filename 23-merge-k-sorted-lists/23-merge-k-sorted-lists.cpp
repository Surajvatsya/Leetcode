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
    
    ListNode*  mergelist(ListNode* list1,ListNode* list2){
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
      
         ListNode* dn = new ListNode(-1);
           ListNode* temp = dn;
        while(temp1 and temp2){
            if(temp1->val> temp2->val)
            {
                 temp->next = temp2;
                temp = temp2;
                  temp2 = temp2->next;
                
            }
            else
            {
                temp->next = temp1;
                temp = temp1;
                 temp1 = temp1->next;
            }
            
           
           
        }
        
        // 1-> 2-> 3
        if(temp1){
             temp->next = temp1;
             // temp-> 1-> 2....
        }
         if(temp2){
              temp->next = temp2;
            
        }
        
        return dn->next;
        
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       int n = lists.size();
        if(n==0)
            return NULL;
        
        while(n>1){
            ListNode* v = mergelist(lists[0],lists[1]);
          
            lists.erase(lists.begin()+0);
            lists.erase(lists.begin()+0);
             lists.push_back(v);
            n-=1;
        }
        return lists[0];
    }
};