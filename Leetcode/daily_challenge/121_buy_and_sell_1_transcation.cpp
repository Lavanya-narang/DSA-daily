class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxr=prices[n-1];
        int maxp=0;
        for(int i=n-2;i>=0;i--)
        {
            maxr=max(maxr,prices[i]);
            maxp=max(maxp,maxr-prices[i]);
        }
        return maxp;
    }
};
