class MyCalendar {
public:
    
    
    map<pair<int, int>, int>mp;
    
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if(mp.empty())
        {
            mp[{start,end}]=1;
            return true;
        }
        
        for(auto &x : mp){
            pair<int,int> p = x.first;
            int s = p.first;
            int e = p.second;
            
            if((start>=s and end<e ) or (start>=s and start<e)    or (end>s and end<=e) or(s>=start and e<=end))
                return false;
            
        }
       mp[{start,end}]=1;
        return true;
        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */