/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        stack<Node*>st;
        Node* curr = head;
        Node* tail = head;
        while(curr){
            tail = curr->next;
            if(curr->child!=NULL){
                if(tail)
                st.push(tail);
                
                curr->next=NULL;
                if(tail)
                tail->prev = NULL;
                curr->next = curr->child;
                curr->child->prev = curr;
                curr->child=NULL;
                
            }
            else{
                if(tail)
                curr=curr->next;
                else break;
            }
        }
        
        while(!st.empty()){
            Node* ele = st.top();
            st.pop();
            curr->next = ele;
            ele->prev = curr;
            while(ele)
            {
                 ele = ele->next;
                curr=curr->next;
            }
            
        }
        
        return head;
        
    }
};