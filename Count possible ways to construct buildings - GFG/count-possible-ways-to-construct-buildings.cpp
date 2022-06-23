// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	#define ll long long
	const int N = 1000000007;
	ll fun(ll i,ll j,ll x,ll n)
	{
	    i = i % N;
	    j = j % N;
	    
	    if(n == x)
	    {
	        return(i + j)% N;
	    }
	    x++;
	    
	    fun(j,(i + j) % N,x,n);
	
	}
	
	int TotalWays(int n)
	{
	    if(n == 1)
	    {
	        return 4;
	    }
	    if(n == 2)
	    {
	        return 9;
	    }
	    ll op = fun(2,3,3,n) % N;
	    
	    return(op * op) % N;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends