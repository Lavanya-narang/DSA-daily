// class Solution {
// public:
//     string mergeAlternately(string word1, string word2) 
//     {
//         string ans="";
//         int i=0,j=0;
//         while(i<word1.length() && j<word2.length())
//         {
//                 ans+=word1[i];
//                 ans+=word2[j];
//             i++;
//             j++;
//         }
//         while(i<word1.length())
//         {
//             ans+=word1[i];
//             i++;
//         }
//         while(j<word2.length())
//         {
//             ans+=word2[j];
//             j++;
//         }
//         return ans;    
//     }
// };
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result = "";
        int i = 0;
        while (i < word1.length() || i < word2.length()) {
            if (i < word1.length()) {
                result += word1[i];
            }
            if (i < word2.length()) {
                result += word2[i];
            }
            i++;
        }
        return result;
    }
};
