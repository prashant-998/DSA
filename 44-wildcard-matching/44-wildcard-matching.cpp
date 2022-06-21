class Solution 
{
public:
     
    
        bool solve(int i, int j, string& pattern , string& str, vector<vector<int> >& dp) 
        {
            if( i< 0 && j< 0)
                return true;
            
            if(i<0 && j>=0)
                return false;
            
            if(i>=0 && j<0)
            {
                for(int k=0; k<=i; k++)
                {
                    if(pattern[k] != '*')
                        return false;
                }
                return true;
            }
            
            if(dp[i][j] != -1 )
                return dp[i][j];
            
            if(pattern[i] == str[j] || pattern[i] == '?')
                dp[i][j] =  solve(i-1, j-1, pattern, str,dp);
            
            else if(pattern[i] == '*')
                dp[i][j] = ( (solve(i,j-1, pattern, str, dp)) || (solve(i-1, j, pattern, str,dp)) );
            
            else 
            {
                dp[i][j] = false;
            }
            return dp[i][j];
        }
        
        bool isMatch(string s, string p) 
        {
            //step1: create DP DS
            vector<vector<int> > dp(p.length(), vector<int> (s.length() , -1));
            return solve(p.length()-1, s.length()-1, p, s, dp);
        }
    
};