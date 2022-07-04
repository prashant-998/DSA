// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution 
{
  public:
  string bin(int k)
  {
        string ans = "";
        while(k > 0)
        {
            if(k%2 == 0) ans += '0';
            else ans += '1';
            k = k/2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    int minVal(int a, int b) 
    {
        string bina = bin(a);
        string binb = bin(b);
        while(bina.length() < binb.length())
        {
            bina.insert(0,"0");
        }
        while(binb.length() < bina.length())
        {
            binb.insert(0,"0");
        }
        int c = 0;
        for(int i=0; i<binb.length(); i++)
        {
            if(binb[i] == '1') c++;
        }
        int m = bina.length();
        string ans = "";
        for(int i=0; i<bina.length(); i++)
        {
            if(bina[i] == '1' && c > 0){
                c--;
                ans += '1';
            }
            else if(bina[i] == '0' && m-i <= c && c > 0)
            {
                ans += '1';
                c--;
            }
            else{
                ans += '0';
            }
        }
        int res = 0;
        int n = ans.length();
        for(int i=0; i<ans.length(); i++)
        {
            res += (ans[i] - '0')*pow(2,n-i-1);
        }
        return res;
    }
};
    

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}  // } Driver Code Ends