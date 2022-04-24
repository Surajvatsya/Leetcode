class UndergroundSystem {
public:
    
    
    unordered_map<int,pair<string,int>>mp; 
    unordered_map< string,vector<int> >mp1; 
    
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        mp[id] = { stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        pair<string,int> p = mp[id];
        string route = p.first+" "+stationName;
        int dist = t  - p.second;
        mp1[route].push_back(dist);
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