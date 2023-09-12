// class Solution {
// public:
//     int minDeletions(std::string s) {
//         std::unordered_map<char, int> cnt;
//         int deletions = 0;
//         std::unordered_set<int> used_frequencies;
        
//         for (char c : s) {
//             cnt[c]++;
//         }
        
//         for (auto& kv : cnt) {
//             int freq = kv.second;
//             while (freq > 0 && used_frequencies.find(freq) != used_frequencies.end()) {
//                 freq--;
//                 deletions++;
//             }
//             used_frequencies.insert(freq);
//         }
        
//         return deletions;
//     }
// };



class Solution {
public:
    int minDeletions(string s) {
        int freq[26]={0};
        
        int l=s.length();
        
        for(int i=0;i<l;i++)
            freq[s[i]-'a']++;
        
        int ans=0;
        for(int i=0;i<26;i++)
        {
            if(freq[i]==0)
                continue;
            for(int j=0;j<26;j++)
            {
                if(i!=j && freq[i]==freq[j])
                {
                    freq[i]--,ans++,i--;
                    break;
                }
            }
        }
        return ans;
    }
};
