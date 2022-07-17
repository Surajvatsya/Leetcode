class MyHashSet {
public:
     vector<list<int>>v;
    int n;
    MyHashSet() {
       n = 10;
        v=vector<list<int>>(n);
    }
    
    void add(int key) {
        //contain check impo nhi to duplicate v insert ho jayga
        if(contains(key))
            return;
       int ind =key%n;
        v[ind].push_back(key);
    }
    
    void remove(int key) {
        if(!contains(key))
            return;
         int ind =key%n;
        //find position
        auto x = find(v[ind].begin(), v[ind].end(), key);
        
        // delete that position
        v[ind].erase(x);
          
    }
    
    bool contains(int key) {
         int ind =key%n;
        
        //rem this
         if(  find(v[ind].begin(), v[ind].end(), key) != v[ind].end() )
             return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */