class Solution {
public:
    int numJewelsInStones(string jewels, string stones) 
    {
        int ans=0;
        //tc:o(n) sc:o(jewel.length)
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
        //tc o(n) sc o(1)
        for (int i = 0; i < jewels.size(); i++){
        ans+= count(stones.begin(), stones.end(), jewels[i]);
    }
        return ans;      
    }
};
