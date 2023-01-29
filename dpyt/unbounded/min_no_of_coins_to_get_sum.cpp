int mincount(int coins[],int sum,int n)
{
    int table[sum+1];
    table[0]=0;
    for(int i=1;i<=sum;i++)
    {
        table[i]=INT_MAX;
    }
    for(int i=1;i<=sum;i++)
    {
        for(int j=0;j<=n;i++)
        {
            if(coins[j]<=i)
            {
                int sub=table[i-coins[j]];
                if(sub!=INT_MAX && sub+1<table[i])
                {
                    table[i]=sub+1;
                }
            }
        }
    }
    if(table[sum]==INT_MAX)
    {
        return -1;
    }
    return table[sum];
}
