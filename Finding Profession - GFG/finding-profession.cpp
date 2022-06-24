// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution
{
   char solve(int level, int pos)
   {
       if(level==1)
       {
           return 'e';
       }
       if(pos==0)
       {
           return 'e';
       }
       
       if(pos % 2 == 0)
       {
           return solve(level-1,pos/2);
       }
       else if(solve(level-1,pos/2) =='d' && pos % 2!=0)
       {
           return 'e';
       }
       else if(solve(level-1,pos/2) =='e' && pos%2!=0){
           return 'd';
       }
   }
public:
   char profession(int level, int pos)
   {
       pos = pos-1;
       solve(level,pos);
   }
};
// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int level, pos;
        cin>>level>>pos;
        
        Solution ob;
        if(ob.profession(level, pos) == 'd')
            cout<<"Doctor\n";
        else
            cout<<"Engineer\n";
    }
    return 0;
}  // } Driver Code Ends