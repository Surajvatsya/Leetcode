// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
int t[100][100];
int solve(int *arr, int i, int j, int n){
    
 
        
    if(i>=j)
    return 0;
    
    if(t[i][j]!=-1)
    return t[i][j];
    
     int ans = INT_MAX;
     
    for(int k=i; k<j; k++){
        
        // In exponential time algorithms, the growth rate doubles
        // with each addition to the input (n).
         int  temp = solve(arr,i,k,n) + solve(arr,k+1,j,n) + (arr[i-1]*arr[k]*arr[j]);
         ans = min(temp,ans);
         
        }
        
        
        //is i and j  k lye yhi ans h
    return t[i][j]=ans;
}

    int matrixMultiplication(int n , int arr[])
    {
        int i=1;
        int j = n-1;
        
        // i and j change ho rha h
           memset(t,-1,sizeof(t));
        
       return solve(arr,i,j,n);
    
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends