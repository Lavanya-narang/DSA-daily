// class Solution {
// public:
//     int maxDepth(string s) 
//     {
//         int ans=0,curr=0;
//         for(int i=0;i<s.size();i++)
//         {
//             if(s[i]=='(')
//             {
//                 ans=max(ans,++curr);
//             }
//             else if(s[i]==')')
//             {
//                 curr--;
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int maxDepth(string s) 
    {
        stack<char>st;
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                st.push('(');
            }
            else if(s[i]==')')
            {
                int x=st.size();
                st.pop();
                ans=max(ans,x);
            }
        }
        return ans;
    }
};
