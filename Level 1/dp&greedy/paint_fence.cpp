#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n ;
  cin >> n ;
  int k ;
  cin >> k ;

  //write your code here
  vector<long>dp(n+1);
  long same=0;
  long diff=k;
  dp[1]=same+diff;
  for(int i=2;i<dp.size();i++)
  {
      same=diff;
      diff=dp[i-1]*(k-1);
      dp[i]=same+diff;
  }
  cout<<dp[n];
}
