// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) 
    {
        long long low=0,high=n,mn;
        while(low<=high)
        {
            long long mid=(high+low)/2;
            if(isBadVersion(mid)==1)
            {
               mn=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return mn;
    }
};
