class Solution 
{
public:
    string getPermutation(int &n, int &k) 
    {
        string s="";
        for(int i = 1;i<=n;i++)
        {
            s+=to_string(i);
        }
        
        // we used k>1 not k==0 because we have 
        // already created 1st so we need k-1th permutation.
        while(k>1)
        {
            // this funtion is used to find next permutation
            next_permutation(s.begin(),s.end());
            k--;
        }
        return s;
    }
};