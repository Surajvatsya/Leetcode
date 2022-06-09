// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++


class Solution
{
    private:
    int findLCS(string str1, string str2){
         int n = str1.length();
         int m = str2.length();
         int t[n+1][m+1];
         for(int i=0; i<n+1; i++){
             for(int j=0; j<m+1; j++){
                 if(i==0 or j==0)
                     t[i][j]=0;
             }
         }
         for(int i=1; i<n+1; i++){
             for(int j=1; j<m+1; j++){
                 if(str1[i-1]==str2[j-1])
                     t[i][j]=1+t[i-1][j-1];
                 else
                     t[i][j]=max(t[i][j-1], t[i-1][j]);
             }
         }
         return t[n][m];
         
         
     }
    
    public:
    //Function to find length of shortest common supersequence of two strings.
    
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        //code here
         int l =  findLCS(X,Y);
        int ans = X.length()-l + Y.length() -l + l;
        return ans;
    }
};

// { Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}

  // } Driver Code Ends