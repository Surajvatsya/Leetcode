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
```