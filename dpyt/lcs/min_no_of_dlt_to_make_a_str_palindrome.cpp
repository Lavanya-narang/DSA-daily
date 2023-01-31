int lcs(string a,string b,int n)
{
    int dp[n+1][n+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
            }
            else if(a[i-1]==b[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][n];
}
int minDeletions(string str, int n) { 
    //complete the function here 
string a=str;
reverse(str.begin(),str.end());
    int lps=lcs(str,a,n);
    int ans=n-lps;
    return ans;
} 
