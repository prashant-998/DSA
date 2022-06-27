class Solution 
{
public:
    int minPartitions(string n) 
    {
        int len = n.length();
        int max_digit_from_string = 0;
        
        //The auto keyword specifies that the type of the variable that is being declared will be automatically deducted from its initializer. 
        for(auto element:n)
        {
            //convert the string number into integer by substracting the ascii value.
            int digit = element-'0';
            max_digit_from_string = max(max_digit_from_string, digit);
        }
        return max_digit_from_string;
    }
};