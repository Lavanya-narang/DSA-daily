// class Solution {
// public:
// //TC:O(N) SC:O(N)
//     string removeStars(string s) 
//     {
//         string ans="";
//         stack<char>st;
//         int n=s.length();
//         for(int i=0;i<n;i++)
//         {
//             if(s[i]=='*')
//             {
//                 st.pop();
//             }
//             else
//             {
//                 st.push(s[i]);
//             }
//         }
//         while(!st.empty())
//         {
//             ans+=st.top();
//             st.pop();
//         }
//         reverse(ans.begin(),ans.end());
//         return ans;
//     }
// };


class Solution {
public:
    string removeStars(string s) 
    {
        int j=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='*')
            {
                j--;
            }
            else {
                s[j]=s[i];
                j++;
            }
        }
        return s.substr(0,j);
    }
};
