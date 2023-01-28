bool css(int arr[],int sum,int n)
{
    int dp[n+1][sum+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(j==0)
            {
                dp[i][j]=0;
            }
            if(i==0)
            {
                dp[i][j]=1;
            }
            if(arr[i-1]<=j)
            {
                dp[i][j]=dp[i-1][j]+dp[i-1][j-arr[i-1]];
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}
