// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:

void solve(vector<int>op, vector<int> ip,int n, vector<int> &ans){
    if(ip.size()==0){
       int s = 0;
       for(int i=0; i< op.size(); i++)
       s+=op[i];
       ans.push_back(s);
       return; 
    }
    
    vector<int>op1 = op;
    
    op1.push_back(ip[0]);
    ip.erase(ip.begin());
    
     solve(op1,ip,n,ans);
     
     solve(op,ip,n,ans);
    
    
}


    vector<int> subsetSums(vector<int> arr, int N)
    {
         vector<int>ans;
         vector<int> op ;
         
         solve(op,arr,N,ans);
         return ans;
         
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends