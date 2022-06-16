class Solution
{
    public:
    
    // dp vector for memoization
    vector<vector<int>>dp;
    
    //function to check for pallindrome
    int is_pallindrome(string &s,int i,int j)
    {
        if(i>=j)
        {
            return 1;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(s[i]==s[j])
        {
            return dp[i][j]=is_pallindrome(s,i+1,j-1);
        }
        return dp[i][j]= 0;
    }
    string longestPalindrome(string  s) 
    {
        int n=s.length();
        int mx=0;
        string ans; // storing ans
        
        //resizing our dp
        dp.resize(n,vector<int>(n,-1));
        for(int i=0;i<n;++i)
        {
            for(int j=i;j<n;++j)
            { 
                //if string from i to j is  a pallindrome and its length is max so then just store it as ans
                if(is_pallindrome(s,i,j))
                {
                    if(j-i+1>mx)
                    {
                        mx=j-i+1;
                        ans=s.substr(i,j-i+1);
                    }
                }
            }
        }
        return ans; //just return the ans
}
};