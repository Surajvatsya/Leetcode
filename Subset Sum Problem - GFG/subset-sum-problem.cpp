// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(vector<int>A, int B){
        // code here 
        int n = A.size();
    int t[n+1][B+1];

    for(int i=0; i<n+1; i++){
        for(int j=0; j<B+1; j++){
            if(i==0){
                t[i][j]=0;
            }
            if(j==0){
                t[i][j]=1;
            }
        }
    }

    for(int i=1; i<n+1; i++){
        for(int j=1; j<B+1; j++){
            if(A[i-1]<=j){
                t[i][j] = (t[i-1][j-A[i-1]] or t[i-1][j]);
            }
            else
            t[i][j] = t[i-1][j];
        }
    }
    return t[n][B];
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends