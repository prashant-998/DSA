// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        //take set as s
        set<char>s;
        
        //itrate through string
        for(char c:str)
        
        //insert charcters in the set
        s.insert(c);
        
        //this map will store characters as well as its count
        unordered_map<char,int>m;
        
        //pointers
        int i = 0;
        int j = 0;
        
        //when all charcters are unique
        int ans = str.size(); 
        
        //size of set
        int n = s.size();
        
        while(i<str.size())
        {
            m[str[i]]++;
            if(m.size() == n)
            {
                while(m[str[j]]>1)
                {
                    //decreasing characters count
                    m[str[j]]--;
                    j++;
                }
                ans = min(ans,i-j+1);
            }
            i++;
        }
        return ans;
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}  // } Driver Code Ends