class TreeAncestor 
{
    vector<vector<int>>v;
    int log;
public:
    
    TreeAncestor(int n, vector<int>& parent) 
    {
       log=ceil(log2(n))+1; 
       v=vector<vector<int>>(n,vector<int>(log)); 
       for(int i=0;i<log;i++)
       {
           for(int j=0;j<n;j++)
           {
               if(i==0){v[j][i]=parent[j];}
               else
               {
                   if(v[j][i-1]!=-1)
                   v[j][i]=v[v[j][i-1]][i-1];
                   else v[j][i]=-1;
               }
           }
       }
    }
    
    int getKthAncestor(int node, int k) 
    {
        int i;
        for(i=0;i<log;i++)
        {
            if(((k>>i)&1)==1)
                node=v[node][i];
            if(node==-1)return node;
        }
        
        return node;

    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */