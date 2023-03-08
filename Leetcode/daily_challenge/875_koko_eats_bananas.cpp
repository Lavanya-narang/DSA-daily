class Solution {
public:
bool isvalid(vector<int>& piles,int h,int mid)
{
    long long midt=0;
    for(int i=0;i<piles.size();i++)
    {
        if(piles[i]%mid==0)
        {
            midt+=piles[i]/mid;
        }
        else
        {
            midt+=piles[i]/mid+1;
        }
    }
    if(midt>h)
    {
        return false;
    }
    return true;
}
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int ans=0,low=1,high=0,n=piles.size();
        for(int i=0;i<n;i++)
        {
            if(piles[i]>high)
            {
                high=piles[i];
            }
        }
            while(low<=high)
            {
                int mid=low+(high-low)/2;
                if(isvalid(piles,h,mid))
                {
                    ans=mid;
                    high=mid-1;
                }
                else
                {
                    low=mid+1;
                }
            }
            return ans;
    }
};

