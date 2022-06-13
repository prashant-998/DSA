class Solution {
public:
    int game(int n,int k)
    {
        //Base Case
        if (n == 1)
        {
            return 0;
        }
        else 
        {
            //circluar round 
            return(game(n-1,k)+k)%n;
        }
    }
    int findTheWinner(int n, int k) 
    {
        //indexing incresed by one
        return game(n,k)+1;
    }
};