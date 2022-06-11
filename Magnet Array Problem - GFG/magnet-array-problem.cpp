// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
        void nullPoints(int n, double magnets[], double getAnswer[])
    {
        //n-1 to find forces between two adjacent magnet
        for(int i=0;i<n-1;i++)
        {
            //it stores ans between 
            //1st and 2nd magnetn      //low     //high 
            getAnswer[i]=neutral_point(magnets[i],magnets[i+1],magnets,n);
        }
    }
    double neutral_point(double low,double high,double magnets[],int n)
    {
        while(low<high)
        {
            double mid=(low+high)/2;
            
            double totalForce=0;
            
            //if mid is a neutral point
            //Ex: [0,10,20,30]
            //initially low=0, high=10
            //mid=5
            for(int i=0;i<n;i++)
            {
                            //distance between two magnets
                totalForce+=1/(mid-magnets[i]);//1/5+1/(-5)+1/(-15)+1/(-25)
                                              //1/5,1/5 gets canceled               
            }
            
           //when to stop iteration ,close to zero
            if(abs(totalForce)<0.000001)
            {
                return mid;
            }
            //force on left is too much
            //force on right is too less
            //to increase move closer to first magnet,
            //away from other three magnets
            else if(totalForce<0)
            {
                high=mid;//mid->5
            }
            else
            {
            //low[0,5]high, mid->2.5
            //force on left is too less
            //force on right is too more
            //to decrease move closer to second magnet,
            //closer to other three magnets
                low=mid;//low[2.5,5]high, mid->3.75 and so on
            }
        }
        return low;
    }
    
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        double magnets[n], getAnswer[n];
        for(int i=0;i<n;i++)
        cin>>magnets[i];
        Solution ob;
        ob.nullPoints(n, magnets, getAnswer);
        
        for(int i=0; i<n-1; i++)
            printf("%0.2lf ",getAnswer[i]);
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends