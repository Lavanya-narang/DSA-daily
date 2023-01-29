//recursive and memoized
int lcs(string x,string y,int n,int m)
{
    if(n==0 || m==0)
    {
        return 0;
    }
    //memoized
    if(dp[n][m]!=-1)
    {
        return dp[n][m];
    }
        if(x[n-1]==y[m-1])
    {
        return dp[n][m]=1+lcs(x,y,n-1,m-1);
    }
    else
    {
        return dp[n][m]=max(lcs(x,y,n,m-1),lcs(x,y,n-1,m));
    }
}
//top down code
int lcs(string x,string y, int n,int m,dp[n][m])
{
    for(int i=0;i<m+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
            }
        }
    }
    for(int i=1;i<m+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            if(x[i-1]==y[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j]);
            }
        }
    }
    return dp[m][n];
}
