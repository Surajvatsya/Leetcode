class MyHashMap {
    private:
    vector< list< pair< int,int > >>v;
    int n;
     int index(int key)
    {
        return key%n;
    }
    auto search(int key){
        int i = index(key);
        auto it =  v[i].begin();
        for(it=v[i].begin(); it!=v[i].end(); it++)
        if(it->first==key)
            return it;
         return v[i].end();   
    }
    bool contains(int key){
        int i = index(key);
        if(search(key)!=v[i].end()){
            return true;
        }
        return false;
    }
    
public:
    MyHashMap() {
        n = 100;
        v.resize(n);
    }
    
   
    
    
    
    void put(int key, int value) {
        //if it contains just change the value of that key
        if(contains(key)){
            auto it = search(key);
            it->second = value;
        }
        else{
            int i = index(key);
            v[i].push_back({key,value});
        }
        
        //else push another node of key and value pair
    }
    
    int get(int key) {
        if(contains(key)){
            auto it = search(key);
            return it->second ;
        }
        else
            return -1;
    }
    
    void remove(int key) {
        if(!contains(key))
            return;
        int i = index(key);
        v[i].erase(search(key));
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */