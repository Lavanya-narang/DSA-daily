class Solution {
public:
//     int partitionString(string s) 
//     {
//         //TC:O(n) SC:O(n)
//         int n=s.length(),ans=0;
//         unordered_map<char,int>mp;
//         for(int i=0;i<n;i++)
//         {
//             if(mp[s[i]]>0)
//             {
//                 ans++;
//                 mp.clear();
//             }
//             mp[s[i]]++;
//         }
//         return ans+1;
//     }
  
  int partitionString(string s) 
    {
        //TC:O(n) SC:O(26)
        vector<int>freq(26,-1);
         int n=s.length();
        int ans=1,substrstart=0;
        for(int i=0;i<n;i++)
        {
            if(freq[s[i]-'a']>=substrstart)
            {
                ans++;
                substrstart=i;
            }
            freq[s[i]-'a']=i;
        }
        return ans;
    }
};
