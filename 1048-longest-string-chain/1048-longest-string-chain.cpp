class Solution 
{
public:
    int longestStrChain(vector<string>& words) 
    {
       unordered_map<string,int>dp;
        int ans=0;
        
        //if we sort normaly it will sort in alphabetical order
        //so, we use length to sort correctly
        sort(words.begin(),words.end(), sortByLength);
       
        //start iterating over each word in words
        for(string word:words)
        {
            //remove character one by one
            for(int i=0;i<word.length();i++)
            {
                //word="bca"
                //ca,ba,bc
                string predecessor=word.substr(0,i)+word.substr(i+1);
                //check if it is in the map,
                //and return the best possible length
                dp[word]=max(dp[word],dp[predecessor]+1);
            }
            ans=max(ans,dp[word]);
        }
        return ans;
    }
    
    //return boolean value after getting sorted by length
    static bool sortByLength(string& s1,string& s2)
    {
        //return true
        return s1.length()<s2.length();
    }
};