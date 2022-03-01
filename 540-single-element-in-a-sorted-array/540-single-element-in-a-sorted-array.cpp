class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        if(a.size()==1)
            return a[0];
        for(int i=0; i<a.size(); i+=2){
            if(a[i]!=a[i+1])
                return a[i];
        }
        return -1;
    }
};