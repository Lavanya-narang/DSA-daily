int lcsubstr(string x,string y,int n,int m,int dp[n][m])  
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
            else{
                dp[i][j]=0;
            }
        }
    }
    return dp[n][m];
}
