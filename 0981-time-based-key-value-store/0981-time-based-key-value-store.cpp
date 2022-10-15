class TimeMap
{
    public:

        unordered_map<string, vector<pair<int, string>>> mp;

    TimeMap() {}

    void set(string key, string value, int timestamp)
    {
        mp[key].push_back({ timestamp,
            value });
    }

    string get(string key, int timestamp)
    {
       
        string s = "";
        vector<pair<int, string>> &v = mp[key];
        
        int idx = -1;
        int l=0;
        int r = v.size() - 1;
        while(l<=r){
            int m = l + (r-l)/2;
            if(v[m].first <= timestamp)
            {
                idx = m;
                  l = m+1;
                
            }
            else
                r = m-1;
        }
        
        if(idx==-1)
            return "";
        return v[idx].second;
    }
};

/**
 *Your TimeMap object will be instantiated and called as such:
 *TimeMap* obj = new TimeMap();
 *obj->set(key,value,timestamp);
 *string param_2 = obj->get(key,timestamp);
 */