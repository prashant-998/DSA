// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxCoins(int A[], int B[], int T, int N) {
        // code here
        int coins = 0;
        while(T--){
            //count max gold and max index
            int max = -1, maxIndex = -1;
            for(int i=0; i<N; i++)
            {
                //plates count is greater then zero
                //max is less then upcoming gold coins
                if(A[i]>0 && max<B[i])
                {
                    //update max and maxindex
                    max = B[i];
                    maxIndex = i;
                }
            }
            //update coins variable with coins of maxindex
            coins += B[maxIndex];
            //decrement our plate count 
            A[maxIndex]--;
        }
        return coins;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int T,N;
        cin>>T>>N;
        
        int A[N], B[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<N; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.maxCoins(A,B,T,N) << endl;
    }
    return 0;
}  // } Driver Code Ends