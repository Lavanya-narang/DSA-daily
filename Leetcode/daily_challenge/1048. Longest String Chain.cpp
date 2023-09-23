// class Solution {
// public:
//     static bool compare(string s1, string s2)
//     {
//         return s1.size()<s2.size();
//     }
    
//     int longestStrChain(vector<string>& words) 
//     {
//         unordered_map<string, int> dp; //it stores predecessor word and chain size
        
//         //sort(words.begin(), words.end(), [](const string &s1, const string &s2){ return s1.length()<s2.length();});
//         sort(words.begin(), words.end(), compare);
        
//         int len = 1; 
//         for(auto word:words) 
//         {
//             dp[word]=1; 
//             for(int i=0; i<word.length(); i++) 
//             {
//                 //removing ith alphabet from the string and check remaining string is available in the dp 
//                 string pred = word.substr(0,i) + word.substr(i+1); 
                
//                 if(dp.find(pred) != dp.end()) 
//                 {
//                     dp[word] = max(dp[word], dp[pred]+1); 
//                     len = max(len, dp[word]);
//                 }
//             }
//         }
//         return len;    
//     }
// };



class Solution {
public:

    bool dist(string &s1, string &s2, int l1, int l2, bool done){
        if(l1 >= s1.size() && l2 >= s2.size()) return true;
        if(l1 >= s1.size() || l2 >= s2.size()){
            if(!done && s2.size() - l2 == 1) return true;
            return false;
        }
        if(s1[l1] == s2[l2]) return dist(s1, s2, l1+1, l2+1, done);
        return done ? false : dist(s1, s2, l1, l2+1, true);
    }

    int longestStrChain(vector<string>& v) {
        int n = v.size();
        auto comp = [](const string &s1, const string &s2){
            return s1.size() > s2.size();
        };

        sort(v.begin(), v.end(), comp);

        int len;
        int i = 0, j = 0;

        vector<int> dp(n, 1);
        while(i<n && j<n){
            len = v[j].size();
            while(i < n && v[i].size() == len) i++;
            if(i == n) break;
            if(len - v[i].size() != 1) {
                j = i;
                continue;
            }
            int k = i;
            while(k < n && v[k].size() == v[i].size()) k++;
            
            for(int t = i ; t < k ; t++){
                for(int m = j ; m < i ; m ++){
                    if(dist(v[t], v[m], 0, 0, false)) dp[t] = max(dp[t], 1 + dp[m]);
                }
            }
            j = i; i = k;
        }

        int maxm = 1;
        for(int i = 0 ; i < n ; i ++) maxm = max(maxm, dp[i]);
        return maxm;
    }
};
