class Solution {
public:
int dp[366];
int solve(vector<int>&days,vector<int>&cost,int index)
{
    if(index>=days.size())
    {
        return 0;
    }
    if(dp[index]!=-1)
    {
        return dp[index];
    }
    int c1=0,c2=0,c3=0;
    int curr=days[index],after1=index,after7=index,after30=index;
    c1=cost[0]+solve(days,cost,after1+1);
    for(int i=index+1;i<days.size();i++)
    {
        if(days[i]<=curr+6)
        {
                after7=i;
        }
    }
    c2=cost[1]+solve(days,cost,after7+1);
    for(int i=index+1;i<days.size();i++)
    {
        if(days[i]<=curr+29)
        {
                after30=i;
        }
    }
    c3=cost[2]+solve(days,cost,after30+1);
    return dp[index]=min({c1,c2,c3});
}
    int mincostTickets(vector<int>& days, vector<int>& costs) 
    {
        memset(dp,-1,sizeof(dp));
        return solve(days,costs,0);
    }
};
