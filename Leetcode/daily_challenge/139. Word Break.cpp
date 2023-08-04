// class Solution {
// public:
//     bool wordBreak(string s, vector<string>& wordDict) {
//         vector<bool> dp(s.size()+1, 0);
//         dp[0] = true;
//         unordered_set<string> set(wordDict.begin(), wordDict.end());
//         for(int i=1; i<=s.size(); i++){
//             for(int j=0; j<i; j++){
//                 if(dp[j] && set.count(s.substr(j, i-j))){
//                     dp[i] = true;
//                     break;
//                 }
//             }
//         }
//         return dp[s.size()];
//     }
// };
// class Solution {
// public:
//     bool wordBreak(string s, vector<string>& wordDict) {
//         int n = s.size();
//         queue<int> validIndQ;
//         vector<bool> checkedArr(n, false);
//         validIndQ.push(-1); // search from 0

//         while(!validIndQ.empty()) {
//             int startInd = validIndQ.front() + 1;
//             validIndQ.pop();
//             // cout<<"startInd: "<<startInd<<endl;
//             // already checked
//             if(checkedArr[startInd])
//                 continue;
//             for(string _s : wordDict) {
//                 // too long
//                 if(startInd + _s.size() - 1 >= n)
//                     continue;
//                 // cout<<"_S: "<<_s<<endl;
//                 if(s.compare(startInd, _s.size(), _s) == 0) {
//                     validIndQ.push(startInd + _s.size() - 1);
//                     if(startInd + _s.size() - 1 == n-1)
//                         return true;
//                 }
//             }
//             checkedArr[startInd] = true;
//         }
//         return false;
//     }
// };


class Solution {
public:
    bool helper(int si, string s, unordered_set<string>& st, vector<int>& dp) {
        if (si == s.size()) {
            return true;
        }

        if (dp[si] != -1) {
            return dp[si];
        }


        string temp = "";
        for (int i = si; i < s.length(); i++) {
            temp += s[i];
            if (st.find(temp) != st.end()) {
                if (helper(si+temp.length(), s, st, dp)) {
                    dp[si] = 1;
                    return true;
                } 
            }
        }
        dp[si] = 0;
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.length()+1, -1);
        dp[s.length()] = 1;
        unordered_set<string> st;
        for (int i = 0; i < wordDict.size(); i++) {
            st.insert(wordDict[i]);
        }
        return helper(0, s, st, dp);
    }
};
