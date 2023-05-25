class Solution {
public:
    int numJewelsInStones(string jewels, string stones) 
    {
        int ans=0;
        // unordered_map<char,int>mp;
       
        // for(int i=0;i<jewels.size();i++)
        // {
        //     mp[jewels[i]]++;
        // }
        // for(int i=0;i<stones.size();i++)
        // {
        //     if(mp.find(stones[i])!=mp.end())
        //     {
        //         ans++;
        //     }
        // }
        for (int i = 0; i < jewels.size(); i++){
        ans+= count(stones.begin(), stones.end(), jewels[i]);
    }
        return ans;      
    }
};
