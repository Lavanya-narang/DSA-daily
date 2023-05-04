class Solution {
public:
    bool findap(vector<int>temp)
    {
        if(temp.size()<=2)
        {
            return true;
        }
        sort(temp.begin(),temp.end());
        int diff=temp[1]-temp[0];
        for(int i=1;i<temp.size();i++)
        {
            if(temp[i]-temp[i-1]!=diff)
            {
                return false;
            }
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) 
    {
        int ls=l.size();
       vector<bool>ans;
       for(int i=0;i<ls;i++)
       {
           vector<int>temp;
           for(int j=l[i];j<=r[i];j++)
           {
               temp.push_back(nums[j]);
           }
           ans.push_back(findap(temp));
       }
       return ans; 
    }
};
