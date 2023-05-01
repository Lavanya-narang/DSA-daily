class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) 
    {
        int n=aliceSizes.size(),m=bobSizes.size();
        vector<int>ans;
        int sa=0,sb=0;
        sort(aliceSizes.begin(),aliceSizes.end());
        sort(bobSizes.begin(),bobSizes.end());
        for(int i=0;i<aliceSizes.size();i++)
        {
            sa+=aliceSizes[i];
        }
        for(int i=0;i<bobSizes.size();i++)
        {
            sb+=bobSizes[i];
        }
        int diff=(sa-sb)/2;
        for(int i=0;i<aliceSizes.size();i++)
        {
            int low=0,high=bobSizes.size()-1;
            while(low<=high)
            {
                int mid=(low+high)/2;
                if(bobSizes[mid]==aliceSizes[i]-diff)
                {
                    ans.push_back(aliceSizes[i]);
                    ans.push_back(bobSizes[mid]);
                    return ans;
                }
                else if(bobSizes[mid]>aliceSizes[i]-diff)
                {
                    high=mid-1;
                }
                else if(bobSizes[mid]<aliceSizes[i]-diff)
                {
                    low=mid+1;
                }
            }
        }
        return ans;
    }
};
