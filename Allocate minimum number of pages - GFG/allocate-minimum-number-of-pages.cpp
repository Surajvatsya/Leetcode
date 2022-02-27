// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    
   bool isValid(int mid,int A[],int M, int n){
       int st=1;
       int sm=0;
    //   int n = sizeof(A)/sizeof(A[0]);
       for(int i=0; i<n; i++){
           sm+=A[i];
           if(sm>mid)
          {
               st++;
               sm=A[i];
          }
          if(st>M)
          return false;
       }
       return true;
   }
    
    int findPages(int A[], int N, int M) 
    {
        
        if(N<M)
        return -1;
        
       int mx = 0;
       int ans = -1;
       int s = 0;
       for(int i=0; i<N; i++){
           s+=A[i];
           if(A[i]>mx)
           mx=A[i];
       }
       
       int l = mx;
       int r = s;
       while(l<=r){
           int mid = r+(l-r)/2;
           if(isValid(mid,A,M,N))
        {
              r = mid-1;
              ans = mid;
        }
           else
           l=mid+1;
       }
       return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends