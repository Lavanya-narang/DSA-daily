// class Solution {
// public:
//     int countGoodSubstrings(string s) 
//     {
//         int ans=0;
//         if(s.length()<3)
//         {
//             return 0;
//         }
//         for(int i=0;i<s.length()-2;i++)
//         {
//             if(s[i]!=s[i+1] and s[i]!=s[i+2] and s[i+1]!=s[i+2])
//             {
//                 ans++;
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int countGoodSubstrings(string s) 
    {
        int ans=0,i=0,j=0,k=3;
        unordered_map<char,int>mp;
        while(j<s.length())
        {
            mp[s[j]]++;
            if(j-i+1<k)
            {
                j++;
            }
            else if(j-i+1==k)
            {
                if(mp.size()==k)
                {
                    ans++;
                }
                mp[s[i]]--;
                if(mp[s[i]]==0)
                {
                    mp.erase(s[i]);
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};
