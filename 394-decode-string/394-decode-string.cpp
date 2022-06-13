class Solution 
{
public:

    //create "num" copies of str [ex: num = 3, str = "abc" => ans = "abcabcabc"]
    string decode_handler(int num, string str)
    {
        string ans = "";
        while(num--)
            ans+=str;
        return ans;
    }
    
    //recursive function to decode string (pos is pass by reference to keep track of pointer in same string)
    string decode_helper(int &pos, string s)
    {
        int n = s.size();
        int num = 0;
        string plaintext = "";
        
        for(; pos < n; ++pos)
        {
            if(s[pos] >= '0' and s[pos] <='9')  //store number of times to send to decode_handler
                num = num*10 + s[pos] - '0';   //handle double digits ( ex: 10[a] )
            
            else if(s[pos] >='a' and s[pos] <= 'z') //if english letter, append to plaintext
                plaintext += s[pos];
            
            else if(s[pos] == '[') // if open brace, deocde inside part first
            {
                string temp = decode_helper(++pos, s); //store result of inside decoding
                plaintext +=  decode_handler(num,temp); //handle outside decoding and add to current plaintext
                num = 0; // reset num for next concatentaion [ex: 3[a]2[b] -> after num = 3, str = "a" done, we need to start again from num =2, str = "b"]
            }   
            else if(s[pos] == ']')  //if close brace, return plaintext to process
                return plaintext; 
        }
        return plaintext; //control will reach here for cases like 2[a]b ->aab -> have to return plaintext outside loop too.
    }
    
    string decodeString(string s) 
    {
        int pos = 0;
        string plaintext = decode_helper(pos,s);
        return plaintext;
    }
};