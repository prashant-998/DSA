// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution 
{

public:
# define ll long long
ll dfs(vector<int>v[],int cur,int par,int* Capacity)
{
    ll req = 0,child = 0;
    for(auto i:v[cur])
    {
        if(i!=par)
        {
            child++;
            ll ch_req = dfs(v,i,cur,Capacity);
            if(ch_req ==-1)
            {
                return -1;
            }
            req = max(req,ch_req);
        }
    }
    if((child*req + Capacity[cur]) > 1e18)
    {
        return -1;
    }
    return child*req+Capacity[cur-1];
}
    long long minimum_amount(vector<vector<int>> &Edges, int N, int S, int *Capacity)
    {
       vector<int>v[N+1];
       for(auto i:Edges)
       {
           v[i[0]].push_back(i[1]);
           v[i[1]].push_back(i[0]);
           
       }
       bool poss = 1;
       //required amount of water from source node to end
       ll req = dfs(v,S,-1,Capacity);
       if(req == -1)
       {
           return -1;
       }
       return req;
    }
};

// { Driver Code Starts.


int main()
 {
	int T;
	cin>> T;
	while (T--)
	{
	    int num, start;
	    cin>>num>>start;
	    int cap[num];
	    for(int i = 0; i<num; i++)
	        cin>>cap[i];
	    
	    vector<vector<int>> Edges(num-1);
	    for(int i=1;i < num;i++){
	        int u, v; cin >> u >> v;
	        Edges[i-1].push_back(u);
	        Edges[i-1].push_back(v);
	    }
	    
	    
    	Solution obj;
	    long long ans = obj.minimum_amount(Edges, num, start, cap);
	    cout << ans << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends