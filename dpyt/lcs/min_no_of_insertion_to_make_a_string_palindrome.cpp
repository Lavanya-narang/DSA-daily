  int lps(string str,string str1,int n)
  {
      int dp[n+1][n+1];
      for(int i=0;i<n+1;i++)
      {
          for(int j=0;j<n+1;j++)
          {
                  dp[i][j]=0;
          }
      }
      for(int i=1;i<n+1;i++)
      {
          for(int j=1;j<n+1;j++)
          {
              if(str[i-1]==str1[j-1])
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
    int countMin(string str){
    //complete the function here
    string str1=str;
    reverse(str.begin(),str.end());
    int lcs=lps(str1,str,str.length());
    int ans=str.length()-lcs;
    return ans;
    }
