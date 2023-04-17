class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) 
    {
        int ans=0;
        int gb=0,mb=0,pb=0;
        vector<int>prefix(travel.size());
        prefix[0]=travel[0];
        for(int i=1;i<prefix.size();i++)
        {
            prefix[i]=prefix[i-1]+travel[i];
        }
        for(int i=0;i<garbage.size();i++)
        {
            string curr=garbage[i];
            for(char x:curr)
            {
                if(x=='M')
                {
                    mb=i;
                }
                if(x=='G')
                {
                    gb=i;
                }
                if(x=='P')
                {
                    pb=i;
                }
            }
            ans+=curr.size();
        }
        if(gb>=1)
        {
            ans+=prefix[gb-1];
        }
         if(mb>=1)
        {
            ans+=prefix[mb-1];
        }
         if(pb>=1)
        {
            ans+=prefix[pb-1];
        }
        return ans;    
    }
};
