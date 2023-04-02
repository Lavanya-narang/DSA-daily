class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) 
    {
        vector<int>ans;
        sort(potions.begin(),potions.end());
        //tc:o(n2) sc:o(1)
        // long long n=spells.size(),m=potions.size();
        // for(long long i=0;i<n;i++)
        // {
        //     long long cnt=0;
        //     for(long long j=0;j<m;j++)
        //     {
        //         long long curr=(long long)spells[i]*potions[j];
        //         if(curr>=success)
        //         {
        //             cnt++;
        //         }
        //     }
        //     ans.push_back(cnt);
        // }

        for(int i=0;i<spells.size();i++)
        {
            int low=0,high=potions.size()-1,start=potions.size();
            while(low<=high)
            {
                int mid=low+(high-low)/2;
                long long curr=(long long)spells[i]*potions[mid];
                if(curr>=success)
                {
                    start=mid;
                    high=mid-1;
                }
                else
                {
                    low=mid+1;
                }
            }
            ans.push_back(potions.size()-start);
        }
        //tc:o(nlogn) sc:o(n)
        return ans;
    }
};
