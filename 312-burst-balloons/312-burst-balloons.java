class Solution {
    public int maxCoins(int[] nums) 
    {
        int n=nums.length+2;
        
        int[] arr=new int[n];
        
        for(int i=1;i<n-1;i++)
        {
            arr[i]=nums[i-1];
        }
        
        arr[0]=1;
        arr[n-1]=1;
        
        int[][] dp=new int[n][n];
        
        //length 1 to n-1.
        for(int len=1;len<n-1;len++)
        {
            // start 1 to n-len.
            for(int start=1;start<n-len;start++)
            {
                int end=start+len-1;
                
                for(int k=start;k<=end;k++)
                {
                    dp[start][end]=Math.max(dp[start][end], dp[start][k-1]+arr[start-1]*arr[k]*arr[end+1]+dp[k+1][end]);
                }
            }
        }
        return dp[1][n-2];
        
    }
}