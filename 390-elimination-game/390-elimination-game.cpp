class Solution 
{
public:
    int lastRemaining(int n) 
    {
        //Base Case
        if(n == 1)
        {
            return 1;
        }
        else
        {
            return 2 * (1 + n / 2 - lastRemaining(n / 2));
        }
    }
};