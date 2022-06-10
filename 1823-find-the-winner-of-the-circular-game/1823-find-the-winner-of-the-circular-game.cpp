class Solution {
public:
    int findTheWinner(int n, int k) 
    {
        //initialized the queue
        queue<int> q;
        
        //pushed the elements into the queue
        for(int i=1;i<=n;i++)
        {
            q.push(i);
        }
        
        //loop will run when queue!=1
        //if it is 1 we will return it
        while(q.size()!=1)
        {
            //counter variable
            int l=k-1;
            
            //when value of l is 0 just pop it
            while(l--)
            {
                //element ouccuring before that element
                int t=q.front();
                //poped from the front 
                q.pop();
                //pused at the last
                q.push(t);
            }
            q.pop();
        }
        return q.front();
        
    }
};