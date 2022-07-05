// /*
// // Definition for a Node.
// class Node {
// public:
//     int val;
//     vector<Node*> neighbors;
//     Node() {
//         val = 0;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val) {
//         val = _val;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val, vector<Node*> _neighbors) {
//         val = _val;
//         neighbors = _neighbors;
//     }
// };
// */

class Solution {
public:
    Node* cloneGraph(Node* node) {
        
        if(node==NULL)
            return node;
        
        //map for original_node -> copy_node
        unordered_map<Node* , Node*> mp;
        
    
        queue<Node*> q;
        q.push(node);
        
        //1 copy bahar hi bna do
         //create a copy of original node
            Node* copy_node = new Node(node->val);
            
            //map original_node -> copy_node
                mp[node]=copy_node;
        
        while(!q.empty()){
            Node*original_node = q.front();
            q.pop();
            
           
             Node* newNode;
            //for each neighbor of original node
                for(auto &nn : original_node->neighbors){
                    
                     
                 if(mp.find(nn)==mp.end()){

                 //create a copy of original node
                 newNode = new Node(nn->val);

                //map original_node -> copy_node
                    mp[nn]=newNode;

                      q.push(nn); 

                  }
                    
              mp[original_node]->neighbors.push_back(mp[nn]);
                       
                }
        }
        
        return copy_node;
    }
};

// class Solution {
// public:
//     Node* cloneGraph(Node* node) {
//         if (!node) {
//             return NULL;
//         }
//          unordered_map<Node*, Node*> copies;
//          queue<Node*> todo;
//         todo.push(node);
        
//         Node* copy = new Node(node -> val);
//         copies[node] = copy;
       
//         while (!todo.empty()) {
//             Node* cur = todo.front();
//             todo.pop();
//              Node* newNode;
//             for (auto &nn : cur -> neighbors) {
//                 if (copies.find(nn) == copies.end()) {
                   
//                          Node* newNode = new Node(nn -> val);
//                      copies[nn] = newNode;
//                     todo.push(nn);
//                 }
//                 copies[cur] -> neighbors.push_back(copies[nn]);
//             }
//         }
//         return copy;
//     }
   
// };