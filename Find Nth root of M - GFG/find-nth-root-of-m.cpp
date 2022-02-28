// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// class Solution{
    class Solution{
	public:
	int NthRoot(int n, int m)
	{
	    long long low=1,high=m;
	    while(high>=low){
	        long long mid=(low+high)/2;
	        if(pow(mid,n)==m){
	            return mid;
	        }
	        else if(pow(mid,n)>m){
	            high=mid-1;
	        }
	        else{
	            low=mid+1;
	        }
	    }
	    return -1;
	}  
};
// 	public:
	
// 	int cal(long long mid, int n){
// 	    long long prod = 1;
// 	    for(int i=1; i<=n; i++){
// 	        prod*=mid;
// 	    }
// 	    return prod;
// 	}
	
	
// 	int bs(long long l, long long r, long long m,int n){
// 	    while(l<=r){
// 	        long long mid = r+(l-r)/2;
// 	        long long val = cal(mid,n);
// 	        if(val == m)
// 	        return mid;
// 	        else if(val>m)
// 	        r=mid-1;
// 	        else
// 	        l= mid+1;
// 	    }
// 	    return -1;
// 	}
	
	
// 	int NthRoot(int n, long long m)
// 	{
// 	    if(n==0)
// 	    return -1;
// 	    if(m==0)
// 	    return 0;
	    
// 	    return bs(1,m,m,n);
// 	}  
// };

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}  // } Driver Code Ends