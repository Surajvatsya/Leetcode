class UndergroundSystem {
public:
    
    //id ko pair kiya    pair({starting point and time of start})
    unordered_map<int,pair<string,int>>mp; 
    
    
    //jab ham phuch gye to start to end ek journey hua jiska string bna lye us string ko pair kr dya t2-t1 k sath where t2 = destination time and t1 = arrival time
    // ab jitne v log us start point se end point tak jaynge sbka t2-t1 ko us string me push krte hue jana h
    unordered_map< string,vector<int> >mp1; 
    
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        mp[id] = { stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        pair<string,int> p = mp[id];
        //whenever you make pair of strings do make " " seprate b/w them
        //bcs a ab same as aa b without space aab aab
        string route = p.first+" "+stationName;
        int t_diff = t  - p.second;
        mp1[route].push_back(t_diff);
    }
    
    double getAverageTime(string startStation, string endStation) {
        vector<int> v = mp1[startStation+" "+endStation];
        int n = v.size();
        double s = 0;
        for(auto &x : v)
            s+=x;
        return s/n;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */