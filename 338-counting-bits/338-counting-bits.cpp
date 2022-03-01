class Solution {
public:
    
    int findOne(int i){
        //convert to binary
        int count=0;
        while(i>0){
            int temp =i%2;
            if(temp)
                count++;
            i=i/2;
        }
        return count;
    }
    
    vector<int> countBits(int n) {
        vector<int>v(n+1);
        for(int i=0; i<n+1; i++){
            v[i] = findOne(i);
        }
        return v;
    }
};