// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


int chocolates(int arr[], int n);


int main()
{
    
    int t;cin>> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        
        cout << chocolates(arr, n);
        cout << endl;
        
    }

}
// } Driver Code Ends


int chocolates(int arr[], int n)
{
    //it will run till low value is less then high
    int low = 0, high = n-1;
    while(low < high)
    {
    
        if(arr[low] > arr[high])
        {
            low++;
            
        }
        else
        {
            high--;
        }
    }
    return arr[low];
}
