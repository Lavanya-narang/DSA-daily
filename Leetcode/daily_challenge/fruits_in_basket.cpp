class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int j=0;
        map<int,int>mp;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            mp[fruits[i]]+=1;
            while(mp.size()>2 && j<=i)
            {
                mp[fruits[j]]--;
                if(mp[fruits[j]]==0)
                {
                    mp.erase(fruits[j]);
                }
                j++;
            }
            ans=max(i-j+1,ans);
        }
        return ans;
    }
};
