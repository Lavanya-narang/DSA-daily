class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) 
    {
        int ans=0;
        int n=items.size();
        for(int i=0;i<n;i++)
        {
            if(ruleKey=="type")
            {
                if(ruleValue==items[i][0])
                {
                    ans++;
                }
            }
            else if(ruleKey=="color")
            {
                if(ruleValue==items[i][1])
                {
                    ans++;
                }
            }
            else
            {
                if(ruleValue==items[i][2])
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};
