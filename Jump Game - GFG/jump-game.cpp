// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution 
{
  public:
  bool jump(int A[], int N, int i)
    {
        if(i == N-1) return true;
        int reach = i + A[i];
        for(int j = i+1; j <= reach; j++)
        {
            if(jump(A, N, j)) return true;
        }
        return false;
    }
    int canReach(int A[], int N) 
    {
        return jump(A, N, 0);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}  // } Driver Code Ends