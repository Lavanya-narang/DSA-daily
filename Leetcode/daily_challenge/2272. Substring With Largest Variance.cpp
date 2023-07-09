//class Solution {
//     int Kadane(int x, int y, string &s)
//     {
//         int d = 0, n = s.size();
//         int ans = 0, ycnt = 0;
//         for(int i = 0; i < n; i++)
//         {
//             if((s[i]-'a') == x)
//             {
//                 d++;
//             }
//             else if((s[i]-'a') == y)
//             {
//                 d--;
//                 ycnt = 1;
//             }
//             if(ycnt != 0)
//             {
//                 ans = max(ans, d);
//             }
//             else
//             {
//                 ans = max(ans, d-1);
//             }
//             if(d < 0)
//             {
//                 ycnt = 0;
//                 d = 0;
//             }
//         }
//         return ans;
//     }
// public:
//     int largestVariance(string s) {
//         vector<int> alphabet(26,0);
//         int ans = 0;
//         for(char &ch : s)
//             alphabet[ch-'a']++;
//         for(int i = 0; i < 25; i++)
//         {
//             if(alphabet[i] == 0) continue;
//             for(int j = i+1; j < 26; j++)
//             {
//                 if(alphabet[j] == 0) continue;
//                 //cout << i << " " << j << endl;
//                 int val = max(Kadane(i,j,s), Kadane(j,i,s));
//                 ans = max(val, ans);
//             }
//         }
//         return ans;
//     }
// };



// class Solution {
// public:
//     int largestVariance(string s) {
//         vector<int>arr(26);
//         for(auto x:s){
//            arr[x-'a']++; 
//         }
//         int ans=0;
//         for(char i='a';i<='z';i++){
//             for(char j='a';j<='z';j++){
//                  if(j==i||arr[i-'a']==0||arr[j-'a']==0)
//                             continue;
//                 for(int k=1;k<=2;k++){
//                    int c1=0;
//                     int c2=0;
//                     for(auto x:s){
//                         if(x==i)
//                             c1++;
//                         if(x==j)
//                             c2++;
//                         if(c2>c1){
//                             c1=0;
//                             c2=0;
//                         }
//                         if(c1>0&&c2>0)
//                         ans=max(ans,c1-c2);
//                     }
//                     reverse(s.begin(),s.end());
//                 }
//             }
//         }
//         return ans;
//     }
// }; 




class Solution {
public:
    int largestVariance(string s) {
    int res = 0;
    unordered_set<char> unique(begin(s), end(s));
    for (char a : unique)
        for (char b : unique) {
            int var = 0, has_b = 0, first_b = 0;
            for (auto ch : s) {
                var += ch == a;
                if (ch == b) {
                    has_b = true;
                    if (first_b && var >= 0)
                        first_b = false;
                    else if (--var < 0) {
                        first_b = true;
                        var = -1;
                    }
                }
                res = max(res, has_b ? var : 0);
            }
        }
    return res;
}
};
