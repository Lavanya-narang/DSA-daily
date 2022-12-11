#include <iostream>
#include <vector>

using namespace std ;

int main() {
  int n ;
  cin >> n ;
  int m ;
  cin >> m ;
  //   write your code here
    int dp[n+1];
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(i<m)
        {
            dp[i]=1;
        }
        else if(i==m)
        {
            dp[i]=2;
        }
        else
        {
            dp[i]=dp[i-1]+dp[i-m];
        }
    }
    cout<<dp[n];
}
