// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int num, int K)
    {
        
        // firstly make priority queue
        priority_queue<int,vector<int>,greater<int>>pq;
        vector<int>Ans;
        
        for(int i=0;i<num;i++)
        {
            if(i<K)
            {
                pq.push(arr[i]);
            }
            else
            {
                //push into the queue
                pq.push(arr[i]);
                
                //extract from top of the queue
                Ans.push_back(pq.top());
                
                //pop the smallest element
                pq.pop();
            }
        }
        while(!pq.empty())
        {
            Ans.push_back(pq.top());
            pq.pop();
        }
        return Ans;
        
    }
};

// { Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    int num, K;
	    cin>>num>>K;
	    
	    int arr[num];
	    for(int i = 0; i<num; ++i){
	        cin>>arr[i];
	    }
	    Solution ob;
	    vector <int> res = ob.nearlySorted(arr, num, K);
	    for (int i = 0; i < res.size (); i++)
	        cout << res[i] << " ";
	        
	    cout<<endl;
	}
	
	return 0;
}
  // } Driver Code Ends