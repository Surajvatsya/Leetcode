​
https://www.youtube.com/watch?v=VNf6VynfpdM
​
```
/*
// Definition for a Node.
class Node {
public:
int val;
Node* next;
Node* random;
Node(int _val) {
val = _val;
next = NULL;
random = NULL;
}
};
**Brute Force**
​
*/
​
​
class Solution {
public:
Node* copyRandomList(Node* head) {
if(!head)
return head;
unordered_map<Node*, Node*>mp;
Node* temp = head;
while(temp){
Node* newNode = new Node(temp->val);
mp[temp]= newNode;
temp=temp->next;
}
mp[NULL] = NULL;
temp = head;
while(temp){
mp[temp]->next = mp[temp->next];
mp[temp]->random = mp[temp->random];
temp=temp->next;
}
return mp[head];
}
};
```
​
​