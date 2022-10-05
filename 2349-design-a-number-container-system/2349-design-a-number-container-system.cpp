class NumberContainers
{
    public:

        unordered_map<int, int> mp;
    unordered_map<int, set < int>> m;

    NumberContainers() {}

    void change(int index, int number)
    {
       	

        if (mp.find(index) != mp.end())
        {
            int ele = mp[index];
            m[ele].erase(index);
            if(m[ele].size()==0)
                m.erase(ele);
            
        }

            
        
        
        mp[index] = number;
        m[number].insert(index);
    }

    int find(int number)
    {
       	
        if (m.find(number) == m.end())
            return -1;

        return *m[number].begin();

       
    }
};

/**
 *Your NumberContainers object will be instantiated and called as such:
 *NumberContainers* obj = new NumberContainers();
 *obj->change(index,number);
 *int param_2 = obj->find(number);
 */