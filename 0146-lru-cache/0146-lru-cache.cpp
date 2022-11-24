// class LRUCache
// {
//     public:

//         struct Node
//         {
//             public: int key;
//             int val;
//             Node * next;
//             Node * prev;
//             Node(int _key, int _val)
//             {
//                 key = _key;
//                 val = _val;
//                 next = NULL;
//                 prev = NULL;
//             }
//         };

//     int n;
//     unordered_map<int, Node*> mp;
//     Node *head = new Node(-1, -1);
//     Node *tail = new Node(-1, -1);

//     void append_at_head(int key, int val)
//     {
//         Node *nn = new Node(key, val);
//         mp[key] = nn;
//         Node *temp = head->next;
        
//          head->next = nn;
        
        
//         nn->next = temp;
//         temp->prev = nn;
       
//         nn->prev = head;
//     }

//     void remove(Node *temp)
//     {
//           mp.erase(temp->key);
//         Node *p1 = temp->prev;
//         Node *p2 = temp->next;
//         p1->next = p2;
//         p2->prev = p1;
      
//         delete temp;
//     }

//     LRUCache(int capacity)
//     {
//         n = capacity;
//         tail->prev = head;
//         head->next = tail;
//     }

//     int get(int key)
//     {
//         if (mp.find(key) == mp.end())
//             return -1;
//         Node *temp = mp[key];
//         int ans = temp->val;

//        	//delete_node(temp);
//         remove(temp);

//        	// insert_at_begin(temp);
//         append_at_head(key, ans);

//         return ans;
//     }

//     void put(int key, int value)
//     {

//        	//case 1: n < 3 mp me ni h
//        	//case 2: n = 3 mp me ni h
//        	//case 3; n = 3 mp me h

//         if (mp.find(key) != mp.end())
//         {
//             remove(mp[key]);
//         }

//         if (mp.size() == n)
//         {
                        
//              remove(tail->prev);

           
//         }

//         append_at_head(key, value);
//     }
// };

// /**
//  *Your LRUCache object will be instantiated and called as such:
//  *LRUCache* obj = new LRUCache(capacity);
//  *int param_1 = obj->get(key);
//  *obj->put(key,value);
//  */

class LRUCache {
public:
class node{
    public:
    int key;
    int val;

    node* next;
    node* prev;

    node(int _key,int _val){
        key = _key;
        val = _val;
        next = NULL;
        prev = NULL;
    }
};


    int n;
    unordered_map<int,node*>mp;

    // head and tail
    node* head = new node(0,0);
    node* tail = new node(0,0);    

    void remove(node* root){
        mp.erase(root->key);
        node* r1 = root->next;
        node* r2 = root->prev;
        r2->next = r1;
        r1->prev = r2;  
    }
    
    void insert(node* root){
        mp[root->key] = root;

        node* temp = head->next;
        head->next = root;
        root->next = temp;
        temp->prev = root;
        root->prev = head;        
    }

    LRUCache(int capacity) {
        n = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.count(key)==0){
            return -1;
        }
        node *temp = mp[key];
        remove(temp);
        insert(temp);
        return temp->val;
    }
    
    void put(int key, int value) {
        node* temp = new node(key,value);
        if(mp.count(key)!=0){
            remove(mp[key]);
        }
        if(mp.size() == n){
            remove(tail->prev);
        }
        insert(temp);
    }
};