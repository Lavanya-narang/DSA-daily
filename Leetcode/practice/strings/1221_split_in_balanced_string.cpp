class Solution {
public:
    int balancedStringSplit(string s) 
    {
        //TC:O(n) SC:O(1)
        int ans=0,total=0;
        for(auto i:s)
        {
            if(i=='L')
            {
                total++;
            }
            else
            {
                total--;
            }
            if(total==0)
            {
                ans++;
            }
        }
        return ans;
    }
    
};
