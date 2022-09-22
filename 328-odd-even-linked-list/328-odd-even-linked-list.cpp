class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        //odd to even
        
        if(!head or !head->next)
            return head;
        
        int i=1;
        
        ListNode* temp = head;
        
        ListNode* even = new ListNode(-1);
        ListNode* odd = new ListNode(-1);
        
        ListNode* e = even;
        ListNode* o = odd;
        while(temp){
            
            if(i&1){
                o->next = temp;
                o=temp;
                
            }
            else{
                e->next = temp;
                e=temp;
            }
            temp=temp->next;
            i++;
        }
        e->next=nullptr;
        // o->next=nullptr;
        o->next = even->next;
        return odd->next;
        
    }
};