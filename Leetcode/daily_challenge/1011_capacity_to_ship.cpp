class Solution {
public:
    bool ispossible(vector<int>wt,int maxw,int days)
    {
        int d=1,currw=0;
        for(auto w:wt)
        {
            if(w+currw<=maxw)
            {
                currw+=w;
            }
            else
            {
                d++;
                currw=w;
            }
        }
        if(d<=days)
        {
            return true;
        }
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=INT_MIN,high=0;
        for(auto w: weights)
        {
            low=max(low,w);
            high+=w;
        }
        int ans;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(ispossible(weights,mid,days))
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
