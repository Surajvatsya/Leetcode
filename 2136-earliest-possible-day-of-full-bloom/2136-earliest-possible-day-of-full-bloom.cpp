typedef pair<int,int> pi;

class compare{
    public :
    bool operator()(pi a, pi b){
        if(a.first == b.first)
            return a.second<b.second;
        return a.first<b.first;
    }
};

class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        priority_queue< pair<int,int> , vector<pair<int,int> >, compare> pq;
        int n = growTime.size();
         
        for(int i=0; i<n; i++){
            pq.push({ growTime[i], plantTime[i]});
        }
        
        int day = 0;
        
        int s = -1;
         
        while(!pq.empty()){
            s+=pq.top().second;
            day = max(day, s+pq.top().first+1 );
            pq.pop();
        }
        
        return day;
    }
};