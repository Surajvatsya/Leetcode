// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    
    bool isPossible(int l,int r,int mid,int n,int *arr, int m){
        int student = 1;
        int sum = 0;
        for(int i=0; i<n; i++){
            sum+=arr[i];
            if(sum>mid){
                student++;
                sum= arr[i];
                if(student>m)
            return false;
            }
            
        }
        return true;
    }
    
    
    
    //Function to find minimum number of pages.
    int findPages(int A[], int n, int m) 
    {
        //N -> NO of books
        //M -> no of students
        if(n<m)
        return -1;
        
        int mx = 0;
        int sum = 0;
        for(int i=0; i<n; i++){
            mx = max(mx, A[i]);
            sum+=A[i];
        }
        int ans = -1;
        int l = mx;
        int r = sum;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(isPossible(l,r,mid,n,A,m)){
                r=mid-1;
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