// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    
//   static bool compare(vector<int>a, vector<int> b){
//         return a[1]<b[1];
//     }
    
    // int activitySelection(vector<int> start, vector<int> end, int n)
    // {
        
    //     vector<vector<int>>v;
    //     for(int i=0; i<n; i++){
    //         v.push_back({start[i],end[i]});
    //     }
        
    //     sort(v.begin(), v.end(), compare);
        
        
    //     int e = v[0][1];
    //     int task = 1;
    //     int i=1;
        
    //     for(int i=0; i<n; i++){
    //         if(v[i][0]>e){
    //             task++;
    //             e=v[i][1];
    //         }
    //     }
    //     return task;
    // }
    
    
    
// shalini21sirothiya
// 12 hours ago

//c++

int activitySelection(vector<int> start, vector<int> end, int n)
   {
       // Your code here
      vector<vector<int>>ans;
      for(int i=0;i<n;i++){
          ans.push_back({start[i],end[i]});
      }
      sort(ans.begin(),ans.end(),[&](vector<int>&a,vector<int>&b){return a[1]<b[1];});
      int take=1,prev=ans[0][1];
      for(int i=1;i<n;i++){
          if(ans[i][0]>prev){
              take++;
              prev=ans[i][1];
          }
      }
       return take;
   }
    
};

// { Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends