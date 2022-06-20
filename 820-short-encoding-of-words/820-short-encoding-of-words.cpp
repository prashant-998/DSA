class Solution 
{
public:
    int minimumLengthEncoding(vector<string>& words) 
    {
        //store word in set so that they can remove easily
        set<string> s(words.begin(), words.end()); 
        
        //for each word find its suffixes and remove from set s if it present
        for(auto &word: words)
        {
            //erase suffixes of a word
            for(int i=1; i<word.size(); i++)
            { 
                s.erase(word.substr(i));
            }
        }
        
        int ans=0;
        
        //all the remaining words in s are valid encoding string
        for(auto word:s)
        {
            ans += word.size()+1;
        }
        
        return ans;
    }
};