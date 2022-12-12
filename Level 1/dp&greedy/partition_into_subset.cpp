#include <iostream> 
#include <vector>

using namespace std ;

   int main() {
      int n ;
      cin>>n ;
      int k ;
      cin>>k ;

     // write your code here
     if(n==0 || k==0 || n<k)
     {
         cout<<0;
     }
     vector<vector<long>> dp(k+1, vector<long>(n+1,0));
     for(int i=1;i<=k;i++)
     {
         for(int j=1;j<=n;j++)
         {
             if(j<i)
             {
                 dp[i][j]=0;
             }
             else if(j==i)
             {
                 dp[i][j]=1;
             }
             else
             {
                 dp[i][j]=dp[i-1][j-1]+ i*(dp[i][j-1]);
             }
         }
     }
     cout<<dp[k][n];
   }
