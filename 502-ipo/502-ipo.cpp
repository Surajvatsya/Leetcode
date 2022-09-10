typedef  pair<int, int>  pi ;
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int>pq; //take max profit for given w
         //take profit for min capital
         priority_queue<pi, vector<pi> , greater<pi>  >mn;
        int n = capital.size();
        for(int i=0;i<n; i++){
            if(w>=capital[i])
                pq.push(profits[i]);
            else
                mn.push({capital[i], profits[i]});
        }
        
        while(k-- and !pq.empty()){
            w+=pq.top();
            pq.pop();
            
            while(!mn.empty() and w>=mn.top().first){
                pq.push(mn.top().second);
                mn.pop();
            }
            
            
        }
        
        
       return w;
        
        
    }
};