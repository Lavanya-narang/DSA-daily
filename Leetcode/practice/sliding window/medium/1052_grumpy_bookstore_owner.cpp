class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) 
    {
        int j=0,sum=0,k=0,mx=0;
        for(int i=0;i<customers.size();i++)
        {
            if(grumpy[i]==0)
            {
                sum+=customers[i];
            }
        }
        while(j<customers.size())
        {
            if(grumpy[j]==1)
            {
                sum+=customers[j];
            }
            if((j-k+1)<minutes)
            {
                j++;
            }
            else if((j-k+1)==minutes)
            {
                mx=max(mx,sum);
                if(grumpy[k]==1)
                {
                    sum-=customers[k];
                }
                j++;
                k++;
            }  
        }
        return mx;
    }
};
