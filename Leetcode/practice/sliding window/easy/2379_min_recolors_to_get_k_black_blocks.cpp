class Solution {
public:
    int minimumRecolors(string blocks, int k) 
    {
        int mn=INT_MAX;
        int ans=0;
        int i=0,j=0;
        int n=blocks.size();
        while(j<n)
        {
            if(blocks[j]=='W')
            {
                ans++;
            }
            if(j-i+1<k)
            {
                j++;
            }
            else if(j-i+1==k)
            {
                if(ans<mn)
                {
                    mn=ans;
                }
                if(blocks[i]=='W')
                {
                    ans--;
                }
                i++;
                j++;
            }
        }
        return mn;
    }
};
