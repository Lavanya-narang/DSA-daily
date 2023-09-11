// class Solution {
// public:
//     string decodeString(string s) {
//          stack<string> chars;
//         stack<int> nums;
//         string res;
//         int num = 0;
//         for(char c : s) {
//             if(isdigit(c)) {
//                 num = num*10 + (c-'0');                              
//             }
//             else if(isalpha(c)) {
//                 res.push_back(c);                
//             }
//             else if(c == '[') {
//                 chars.push(res);
//                 nums.push(num);
//                 res = "";
//                 num = 0;
//             }
//             else if(c == ']') {
//                 string tmp = res;
//                 for(int i = 0; i < nums.top()-1; ++i) {
//                     res += tmp;
//                 }
//                 res = chars.top() + res;
//                 chars.pop(); nums.pop();
//             }
//         }
//         return res;
//     }
// };


class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        for(auto& c:s){
            if(c==']')
            {
                string temp = "",curr = "";
                while(!st.empty() and st.top()!="[")
                {
                    reverse(st.top().begin(),st.top().end());
                    temp += st.top();
                    st.pop();
                }
                st.pop();
                string times = "";
                
                while(!st.empty() and st.top()>="0" and st.top()<="9")
                {
                    times += st.top();
                    st.pop();
                }
                
                reverse(times.begin(),times.end());
                reverse(temp.begin(),temp.end());
                
                int k = stoi(times);
                
                while(k--)
                {
                    curr += temp;
                }
                
                if(!st.empty() and st.top()!="[")
                    st.top() += curr;  
                else
                    st.push(curr);
            }
            
            else{
                string curr = "";
                curr.push_back(c);
                st.push(curr);
            }
        }
        
        string ans = "";
        while(!st.empty()){
            reverse(st.top().begin(),st.top().end());
            ans += st.top();
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};
