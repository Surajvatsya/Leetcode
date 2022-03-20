class Solution {
public:
    
    pair<int,int> findMaxFreq(map<int,int>&mp){
        int mx = INT_MIN;
        int key;
        for(auto &x : mp){
            if(x.second>mx){
                mx=x.second;
                key=x.first;
            }
        }
        return {key,mx};
    }
    
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        //min ->greedy/DP
        
        map<int,int>top;
        map<int,int>bottom;
        for(auto &x : tops)
            top[x]++;
        for(auto &x : bottoms)
            bottom[x]++;
        
      pair<int,int>p=  findMaxFreq(top);
      pair<int,int>q=  findMaxFreq(bottom);
        
        
        int f1 = p.second;
        int f1c = p.first;
        int f2 = q.second;
        int f2c = q.first;
        
        cout<<f1<<f2<<f1c<<f2c<<endl;
        int rtn=0;
        if(f1>f2){
            for(int i=0; i<tops.size(); i++){
                if(tops[i]!=f1c and bottoms[i]!=f1c)
                    return -1;
                else if(tops[i]!=f1c and bottoms[i]==f1c)
                    rtn++;
            }
        }
        else{
            for(int i=0; i<bottoms.size(); i++){
                if(bottoms[i]!=f2c and tops[i]!=f2c)
                    return -1;
                else if(bottoms[i]!=f2c and tops[i]==f2c)
                    rtn++;
            }
        }
        return rtn;
        
    }
};