//recursive code
//memoised code
int knapsack(int wt[],int val[],int w,int n)
{
  if(n==0 || w==0)//base case: weights of items=0 or capacity of bag=0
  {
    return 0;
  }
  if(dp[n][w]!=-1)
   {
     return dp[n[w];
  }           
  if(wt[n-1]<=w)//weight of item less than weight of knapsack
  {
    return dp[n][w]=max(val[n-1]+ knapsack(wt,val,w-w[n-1],n-1),knapsack(wt,val,w,n-1));
  }
  else if(wt[n-1]>0)//weight of item more than weight of knapsack
  {
    return dp[n][w]= knapsack(wt,val,w,n-1);
  }
}
               
//top down code
for(int i=0;i<n+1;i++)
{
  for(int j=0;j<w+1;j++)
  {
    if(i==0 || j==0)
    {
      dp[i][j]==0;
    }
  if(wt[n-1]<=w)
  {
    dp[n][w]=max(val[n-1]+dp[n-1][w-w[n-1]],dp[n-1][w];
  }
  else
  {
    dp[n][w]=dp[n-1][w];
  }
  }              
 }                 
 for(int i=0;i<n+1;i++)
{
  for(int j=0;j<w+1;j++)
  {
    if(wt[i-1]<=j)
    {
      dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1],dp[i-1][j]);
    }
    else
    {
       dp[i][j]=dp[i-1][j];
    }
  }
 }             
               
           
