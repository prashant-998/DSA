// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
        int findNum(int n)
        {
            int low = 0;
            int high = 5*n;//high = 5*6 = 30
            int ans = low;
            while(low<=high)
            {
                int mid = (low+high)/2;
                int zeroes = find_no_of_zeroes_factorials(mid);
                if(zeroes>=n)
                {
                    ans = mid;
                    high = mid-1;
                
                }
                else
                {
                    low = mid+1;
                }
                
            }
            return ans;
        }
            
            int find_no_of_zeroes_factorials(int x)
            {
                //x/5 + x/25 + x/125....  
                int denominator = 5;
                int zeroes = 0;
                while(x>=denominator)
                {
                    zeroes+=(x/denominator);
                    denominator*=5;
                }
                return zeroes;
                
            }
        
};

// { Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}  // } Driver Code Ends