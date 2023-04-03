class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) 
    {//TC:O(nlog(n));   SC:O(1) 
        int ans=0;
        int low=0,high=people.size()-1;
        sort(people.begin(),people.end());
        while(low<=high)
        {
            if(people[low]+people[high]<=limit)
            {
                ans++;
                low++;
                high--;
            }
            else
            {
                ans++;
                high--;
            }
        }
        return ans;
    }
};
