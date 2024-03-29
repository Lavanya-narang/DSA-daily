#include<iostream>
#include<vector>
using namespace std;

void coinchangepermutation(vector<int> coins, int amt){
    vector<int> dp(amt+1);
    dp[0]=1;
    for(int i=1;i<=amt;i++)
    {
        for(int j=0;j<coins.size();j++)
        {
            if(coins[j]<=i)
            {
                int ramt=i-coins[j];
                dp[i]+=dp[ramt];
            }
        }
    }
    cout<<dp[amt];
}

int main()
{
    int n;
    cin >> n;
    vector<int> coins(n,0);                       //coins vector
    for(int i = 0; i < coins.size(); i++){
        cin >> coins[i];
    }
    int amt;                                   // amount to paid
    cin >> amt;
    coinchangepermutation(coins, amt);
    return 0;
}
