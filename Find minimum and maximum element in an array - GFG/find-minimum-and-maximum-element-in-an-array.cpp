// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define ll long long

pair<long long, long long> getMinMax(long long a[], int n) ;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        pair<ll, ll> pp = getMinMax(a, n);

        cout << pp.first << " " << pp.second << endl;
    }
    return 0;
}// } Driver Code Ends


pair<long long, long long> getMinMax(long long arr[], int n) {
    int i = 0;
    long long lo = INT_MAX;
    long long hi = INT_MIN;
    while(i<n){
        lo = min(lo,arr[i]);
        hi = max(hi,arr[i]);
        i++;
    }  
    pair<long long, long long> p;
    p.first = lo;
    p.second = hi;
    return p;
}
    
