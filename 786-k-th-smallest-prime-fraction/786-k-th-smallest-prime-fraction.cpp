typedef pair<int,int> pi;
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<int> ans;
        priority_queue< pair< double ,pair<int,int > >  > pq;
        int n = arr.size();
        
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                
                double val = (double)arr[i]/arr[j] ;
                if(pq.size()<k){
                    pq.push({val, {arr[i],arr[j]} }); 
                     // cout<<arr[i]<<" "<<arr[j]<<endl;   
                }
               
                else if( val < pq.top().first){
                         pq.pop();
                         pq.push({ val , {arr[i],arr[j]} });
                         // cout<<arr[i]<<" "<<arr[j]<<endl;   
                    }
                   
                
                 
            }
            
        }
        
        
        // while(!pq.empty()){
        //     cout<<pq.top().second.first<<" "<<pq.top().second.second <<endl;
        //     pq.pop();
        // }
        
        return {pq.top().second.first,pq.top().second.second} ;
        
    }
};