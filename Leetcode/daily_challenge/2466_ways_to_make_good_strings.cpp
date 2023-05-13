class Solution {
public:
int MOD=1e9+7;
vector<int>dp;
int solve(int len,const int zero,const int one)
{
    if(len==0)
    {
        return 1;
    }
    if(len<0)
    {
        return 0;
    }
    int& result=dp[len];
    if(result!=-1)
    {
        return result;
    }
    result=(solve(len-zero,zero,one)+solve(len-one,zero,one))%MOD;
    return result;
}
    int countGoodStrings(int low, int high, int zero, int one) 
    {
        dp.clear();
        dp.resize(high+1,-1);
        long long result=0;
        for(int len=low;len<=high;len++)
        {
            result=(result+solve(len,zero,one))%MOD;
        }
        return result;
    }
};
