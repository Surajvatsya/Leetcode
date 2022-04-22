class MyHashMap {
public:
    vector<list<pair<int,int>>>v;
    int sz;
    MyHashMap() {
        sz=1000;
        v.resize(sz);
    }
    
    int hash(int key){
        return key%sz;
    }
    
    auto search(int key){
        int i = hash(key);
        auto  it = v[i].begin();
        for(  it = v[i].begin(); it!=v[i].end(); it++){
            if(it->first == key)
                return it;
        }
        return it;
    }
    
    void put(int key, int value) {
        int i = hash(key);
        auto it = search(key);
        if(it!=v[i].end())
            it->second = value;
        
        else
        v[i].push_back({key,value});
    }
    
    int get(int key) {
        int i = hash(key);
        auto it = search(key);
        if(it!=v[i].end()){
            return it->second;
        }
        else
            return -1;
    }
    
    void remove(int key) {
        int i = hash(key);
        auto it = search(key);
        if(it!=v[i].end()){
            v[i].erase(it);
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */