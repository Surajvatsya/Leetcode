class Solution {
public:
    
    set<string>st;
     unordered_map<int,int>flag;
    string s;
    void permute(string &tiles){
        for(int i=0; i<tiles.length(); i++){
            if(flag[i]!=1){
                s+=tiles[i];
                st.insert(s);
                flag[i]=1;
                permute(tiles);
                    flag[i]=0;
               s.pop_back();
            }
            
        }
    }
    int numTilePossibilities(string tiles) {
        permute(tiles);
        return st.size();
    }
};