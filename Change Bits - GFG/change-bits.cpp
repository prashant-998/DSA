// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<int> changeBits(int N) 
    {
        int store = N;
        int len = 0;
        int B;
        vector<int> ans;
        while(N) 
        {
            N /= 2;
            len++;
        }
        
        int g = pow(2, len) - 1;
        int dif = abs(g - store);
        ans.push_back(dif);
        ans.push_back(g);
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        Solution ob;
        auto ans = ob.changeBits(N);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}  // } Driver Code Ends