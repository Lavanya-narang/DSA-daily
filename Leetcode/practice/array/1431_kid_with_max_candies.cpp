class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) 
    {
        //TC:O(n) SC:O(n)
        int n=candies.size(),ans=0;
        vector<bool>result;
         for(auto a:candies)
        {
             ans=max(ans,a);
        }
        for(auto a:candies)
        {
            if(a+extraCandies>=ans)
            {
                result.push_back(true);
            }
            else
            {
                result.push_back(false);
            }
        }
        return result;
    }
};
