class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i=1;i<=n;i++)
            q.push(i);
        
        while(q.size()!=1)
        {
            for(int i=1;i<k;i++)
            {
                int x = q.front();
                q.push(x);
                q.pop();
            }
            q.pop();
        }
        return q.front();
    }
};

